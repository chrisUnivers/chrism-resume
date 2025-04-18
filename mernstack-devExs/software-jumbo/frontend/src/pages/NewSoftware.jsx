import { useState, useEffect } from "react"
import { useSelector, useDispatch } from "react-redux"
import { useNavigate } from "react-router-dom"
import { getAuth } from 'firebase/auth'
import { getStorage, ref, uploadBytesResumable, getDownloadURL } from 'firebase/storage'
import { addDoc, collection, serverTimestamp } from 'firebase/firestore'
import { createSoftware, reset } from "../features/software/softwareSlice"
import {db} from '../firebase.config'
import { v4 as uuidv4 } from 'uuid'
import { toast } from "react-toastify"
import Spinner from "../components/Spinner"
import BackButton from "../components/BackButton"
// softwarename, description, status, imageurl

function NewSoftware() {
    const {user} = useSelector((state) => state.auth)
    const {isLoading, isError, isSuccess, message} = useSelector((state) => state.softwarestore)

    const [name] = useState(user.name)
    const [email] = useState(user.email)

    const [formData, setFormData] = useState({
        softwarename: '',
        imageurl: 'functions',
        description: '',
        images: {}
    })

    const {softwarename, imageurl, images, description} =  formData
    
    
    // For now I'm using static images. This is a work around for now. Need to set up firestore to upload images.
    const [softwareCreated, setSoftwareCreated] = useState(false)

    const dispatch = useDispatch()
    const navigate = useNavigate()

    const auth = getAuth()


    useEffect(() => {
        if(isError) {
            toast.error(message)
        }

        if(isSuccess && softwareCreated) {
            dispatch(reset())
            navigate('/')
        }

        dispatch(reset())
    }, [dispatch, isError, isSuccess, navigate, message])

    
    const onSubmit = async (e) => {
        e.preventDefault()
        setSoftwareCreated(true)

        // Store image in firebase
        const storeImage = async (image) => {
            return new Promise((resolve, reject) => {
                const storage = getStorage()
                const fileName = `${auth.currentUser.uid}-${image.name}-${uuidv4()}`

                const storageRef = ref(storage, 'images/' + fileName)

                const uploadTask = uploadBytesResumable(storageRef, image)

                uploadTask.on('state_changed',  
                    (error) => {
                        reject(error)
                    }, 
                    () => {
                        //successful uploads on complete
                        getDownloadURL(uploadTask.snapshot.ref).then((downloadURL) => {
                        resolve(downloadURL);
                        });
                    }
                    );                  
            } )
        }

        const imgUpUrls = await Promise.all(
            [...images].map((image) => storeImage(image))
        ).catch(() => {
            console.log('Images did not uploaded')
        })

        const formDataUpload = {
            ...formData, imgUpUrls, timestamp: serverTimestamp()
        }

        // since uploaded
        delete formDataUpload.images

        const docRef = await addDoc(collection(db, 'listings'), formDataUpload)

        // For mongodb since still using it for now
        dispatch(createSoftware({ softwarename, description,  imageurl}))
        if(isLoading) {
            return <Spinner />
        }
    }

    const onChange = (e) => {
        if(e.target.files) {
            setFormData((prevState) => ({
                ...prevState,
                images: e.target.files
            }))
        }
        
        if(!e.target.files) {
            setFormData((prevState) => ({
                ...prevState,
                [e.target.id]: e.target.value,
            }))
        }
    }

    return (
        <>
            {console.log(user)}
            <div className="back-btn">
                <BackButton url='/' />
            </div>
            <div className="heading">
                <h1>Create New Software</h1>
                <p>Please fill out the form below</p>
            </div>
                <div className="form">
                    <div className="form-group">
                        <label htmlFor="name">Your name</label>
                        <input type="text" className="form-control" value={name} disabled />
                    </div>
                    <div className="form-group">
                        <label htmlFor="name">Your Email</label>
                        <input type="text" className="form-control" value={email} disabled />
                    </div> 
                    <form onSubmit={onSubmit}>
                        <div className="form-group">
                            <div className="form-group">
                                <label htmlFor="name">Software Name</label>
                                <input className="form-control" type="text" id="softwarename" name="softwarename" value={softwarename} onChange={onChange} placeholder="Enter the name of this software" required/>
                            </div>
                            <label htmlFor="imageurl">Choose An Icon for Your Software</label>
                            <select name="imageurl" id="imageurl" value={imageurl ==='' ? 'functions' : imageurl} onChange={onChange}>
                                <option value="machine">ML Software</option>
                                <option value="analytics">Analytics Software</option>
                                <option value="distribution">Distribution Software</option>
                                <option value="functions">Functions Software</option>
                            </select>
                            {imageurl !== '' && (
                                <div className="img-url-container">
                                    <div className="img-url-icon-bg">
                                        <img src={`/assets/software_svg/firebase_${imageurl}.svg`} alt= "firebase_" className="img-url-icon" />
                                    </div>
                                </div>
                            )}
                        </div>
                        <div className="form-group">
                            <label htmlFor="description">Give your software a description</label>
                            <textarea name="description" id="description"className="form-control" placeholder="Description" value={description} onChange={onChange}></textarea>
                            <label className="formLabel">Software Image</label>
                            <p className="imageurl">Please provide one image for your software.</p>
                            <input className="imageFile" type="file" id="images"  onChange={onChange}max="1" accept=".jpg,.png,.jpeg,.svg" required/>
                        </div>
                        <div className="form-group">
                            <button className="btn btn-block">Submit</button>
                        </div>
                    </form>
            </div>
        </>
    )
}

export default NewSoftware