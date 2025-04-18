import { useState, useEffect } from "react"
import { useNavigate } from 'react-router-dom'
import { toast } from 'react-toastify'
import { FaUser } from "react-icons/fa"
import { useSelector, useDispatch } from 'react-redux'
import { register, reset } from '../features/auth/authSlice'
import {getAuth, createUserWithEmailAndPassword, updateProfile} from 'firebase/auth'
import { setDoc, doc, serverTimestamp } from 'firebase/firestore'
import { db } from '../firebase.config'
import Spinner from '../components/Spinner'


function Register() {
    const [formData, setFormData] = useState({
        name: '',
        email: '',
        password: '',
        password2: ''
    })

    const {name, email, password, password2} = formData

    const [userRole, setuserRole] = useState('user')
    const [vendorId, setVendorId] = useState('')

    const dispatch = useDispatch()
    const navigate = useNavigate()

    const { user, isLoading, isError, isSuccess, message } = useSelector(
        (state) => state.auth
    )

    useEffect(() => {
        if(isError) {
            toast.error(message)
        }

        if(isSuccess || user) {
            navigate('/')
        }

        dispatch(reset())
    }, [isError, isSuccess, user, message, navigate, dispatch])
    
    const onChange = (e) => {
        setFormData((prevState) => ({
            ...prevState,
            [e.target.name]: e.target.value,
        }))
    }

    const onSubmit = async (e) => {
        e.preventDefault()

        try {
            if(password !== password2) {
                toast.error('Passwords do not match')
            } else {
                const userData = {
                    name,
                    email,
                    password
                }
                const auth = getAuth()
            
                const userCredential = await createUserWithEmailAndPassword(auth, email, password)

                const user = userCredential.user

                updateProfile(auth.currentUser, {
                    displayName: name
                })

                const formDataCopy = {...userData}
                delete formDataCopy.password
                formDataCopy.timestamp = serverTimestamp()

                await setDoc(doc(db, 'users', user.uid), formDataCopy)

                dispatch(register(userData))
            }
            

        } catch (error) {
            console.log(error)
        }
        
    }

    if(isLoading) {
        return <Spinner />
    }
    return (
        <>
           <section className="heading">
                <h1>
                    <FaUser /> Register
                </h1>
                <p>Please create an account</p>
            </section>

            <section className="form">
                <form onSubmit={onSubmit}>
                    <div className="form-group">
                        <input type="text" className="form-control" id="name" name="name" value={name} onChange={onChange} placeholder="Enter your name" required />
                    </div>
                    <div className="form-group">
                        <input type="email" className="form-control" id="email" name="email" value={email} onChange={onChange} placeholder="Enter your email" required />
                    </div>
                    <div className="form-group">
                        <input type="password" className="form-control" id="password" name="password" value={password} onChange={onChange} placeholder="Enter your password" required />
                    </div>
                    <div className="form-group">
                        <input type="password" className="form-control" id="password2" name="password2" value={password2} onChange={onChange} placeholder="Confirm password" required />
                    </div>
                    <div className="form-group signup">
                        <select name="role" id="role" value={userRole} onChange={(e) => setuserRole(e.target.value)}>
                            <option value="user">User</option>
                            <option value="vendor">Vendor</option>
                        </select>
                        {userRole === "vendor" && (
                            <input className="form-control" type="text" id="role" name="role" value={vendorId} onChange={(e) => setVendorId(e.target.value)} placeholder="Enter your vendor's code" required/>
                        )}
                    </div>
                    
                    <div className="form-group">
                        <button className="btn btn-block">Submit</button>
                    </div>
                </form>
            </section>
        </>
    )
}

export default Register