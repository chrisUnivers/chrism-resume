import { useState, useEffect } from "react"
import {toast} from 'react-toastify'
import { useNavigate } from 'react-router-dom'
import { getAuth, signInWithEmailAndPassword } from 'firebase/auth'
import { FaSignInAlt } from "react-icons/fa"
import { useSelector, useDispatch } from 'react-redux'
import { login, reset} from '../features/auth/authSlice'
import Spinner from '../components/Spinner'


function Login() {
    const [formData, setFormData] = useState({
        email: '',
        password: '',
    })

    const [firebaseLogin, setFirebaseLogin] = useState(false)

    const {email, password} = formData

    const dispatch = useDispatch()
    const navigate = useNavigate()

    const { user, isLoading, isError, isSuccess, message } = useSelector(
        (state) => state.auth
    )

    useEffect(() => {
        if(isError) {
            toast.error(message)
        }

        if((isSuccess || user) && firebaseLogin) {
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
            const auth = getAuth()

            const userCredential = await signInWithEmailAndPassword(auth, email, password)

            const userData = {
                email,
                password
            }

            if(userCredential.user) {
                setFirebaseLogin(true)
            }

            dispatch(login(userData))
        } catch (error) {
            console.log(error);
        }
    
    }

    if(isLoading) {
        return <Spinner />
    }

    return (
        <>
            <div className="loginpage">
                <section className="heading">
                    <h1>
                        <FaSignInAlt /> Login
                    </h1>
                    <p>Login</p>
                </section>

                <section className="form">
                    <form onSubmit={onSubmit}>
                        <div className="form-group">
                            <input type="email" className="form-control" id="email" name="email" value={email} onChange={onChange} placeholder="Enter your email" required />
                        </div>
                        <div className="form-group">
                            <input type="password" className="form-control" id="password" name="password" value={password} onChange={onChange} placeholder="Enter your password" required />
                        </div>
                        <div className="form-group">
                            <button className="btn btn-block">Submit</button>
                        </div>
                    </form>
                </section>
            </div>
        </>
    )
}

export default Login