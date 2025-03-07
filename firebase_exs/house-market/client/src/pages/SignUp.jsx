import {useState} from 'react'
import {Link, useNavigate} from 'react-router-dom'
import {getAuth, createUserWithEmailAndPassword, updateProfile} from 'firebase/auth'
import OAuth from '../components/OAuth'
import { setDoc, doc, serverTimestamp } from 'firebase/firestore'
import { db } from '../firebase.config'
import ArrowRightIcon from '../assets/svg/keyboardArrowRightIcon.svg?react'
import visibilityIcon from '../assets/svg/visibilityIcon.svg?react'



function signUp() {
    const [showPassword, setShowPassword] = useState(false)
    const [formData, setFormData] = useState({
        name:'',
        email: '',
        password: '',
    })
    const { name, email, password } = formData
    
    const navigate = useNavigate()

    const onChange = (e) => {
        setFormData((prevState) => ({
            ...prevState, [e.target.id]: e.target.value,
        }))
    }

    const onSubmit = async (e) => {
        e.preventDefault()

        try {
            const auth = getAuth()

            const userCredential = await createUserWithEmailAndPassword(auth, email, password)
            
            const user = userCredential.user

            updateProfile(auth.currentUser, {
                displayName: name
            })

            const formDataCopy = {...formData}
            delete formDataCopy.password
            formDataCopy.timestamp = serverTimestamp()

            await setDoc(doc(db, 'users', user.uid), formDataCopy)

            navigate('/')
        } catch (error) {
            console.log(error);
        }
    }
    return (
        <>
            <div className='pageContainer'>
                <header>
                    <p className='pageHeader'>Welcome!</p>
                </header>

                <form onSubmit={onSubmit}>
                    <input type='name' className='nameInput' placeholder='Name' id='name' value={name} onChange={onChange}/>

                    <input type='email' className='emailInput' placeholder='Email' id='email' value={email} onChange={onChange}/>
                    
                    <div className='passwordInputDiv'>
                        <input type={showPassword ? 'text' : 'password'} className='passwordInput' placeholder='Password' id='password' value={password} onChange={onChange} />
                        <img src={visibilityIcon} alt='show password' className='showPassword' onClick={() => setShowPassword((prevState) => !prevState)} />
                    </div>

                    <Link to='/forgot-password' className='forgotPasswordLink'> Forgot Password</Link>

                    <div className='signUpBar'>
                        <p className='signUpText'>Sign Up</p>
                        <button className='signUpButton'>
                            <ArrowRightIcon fill='#ffffff' width='34px' height='34px' />
                        </button>
                    </div>
                </form>

                <OAuth />
                <Link to='/sign-in' className='registerLink'>Sign In Instead</Link>
            </div>
        </>
    )
}

export default signUp