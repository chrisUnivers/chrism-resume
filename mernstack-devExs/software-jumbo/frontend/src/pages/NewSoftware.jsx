import { useState, useEffect } from "react"
import { useSelector, useDispatch } from "react-redux"
import { useNavigate } from "react-router-dom"
import { toast } from "react-toastify"
import { createSoftware, reset } from "../features/software/softwareSlice"
import Spinner from "../components/Spinner"
import BackButton from "../components/BackButton"
// softwarename, description, status, imageurl

function NewSoftware() {
    const {user} = useSelector((state) => state.auth)
    const {isLoading, isError, isSuccess, message} = useSelector((state) => state.softwarestate)

    const [name] = useState(user.name)
    const [email] = useState(user.email)
    
    const [softwarename, setSoftwarename] = useState('functions')
    // For now I'm using static images. This is a work around for now. Need to set up firestore to upload images.
    const [imageurl, setImgUrl] = useState('null')
    const [description, setDescription] = useState('')
    const [softwareCreated, setSoftwareCreated] = useState(false)

    const dispatch = useDispatch()
    const navigate = useNavigate()

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
    
    const onSubmit = (e) => {
        e.preventDefault()
        setSoftwareCreated(true)

        dispatch(createSoftware({ softwarename, description,  imageurl}))
        if(isLoading) {
            return <Spinner />
        }
    }

    return (
        <>
            {/* {console.log(user)} */}
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
                                <input className="form-control" type="text" id="softwarename" name="softwarename" value={softwarename} onChange={(e) => setSoftwarename(e.target.value)} placeholder="Enter the name of this software" required/>
                            </div>
                            <label htmlFor="imageurl">Choose An Icon for Your Software</label>
                            <select name="imageurl" id="imageurl" value={imageurl} onChange={(e) => setImgUrl(e.target.value)}>
                                <option value="machine">ML Software</option>
                                <option value="analytics">Analytics Software</option>
                                <option value="distribution">Distribution Software</option>
                                <option value="functions">Functions Software</option>
                            </select>
                            {imageurl !== 'null' && (
                                <div className="img-url-container">
                                    <div className="img-url-icon-bg">
                                        <img src="/assets/software_svg/firebase_machine.svg" alt= "firebase_" className="img-url-icon" />
                                    </div>
                                </div>
                            )}
                        </div>
                        <div className="form-group">
                            <label htmlFor="description">Give your software a description</label>
                            <textarea name="description" id="description"className="form-control" placeholder="Description" value={description} onChange={(e) => setDescription(e.target.value)}></textarea>
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