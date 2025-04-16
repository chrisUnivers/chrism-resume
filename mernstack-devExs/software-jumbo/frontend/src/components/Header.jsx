import {FaSignInAlt, FaSignOutAlt, FaUser, FaNodeJs} from 'react-icons/fa'
import { Link, useNavigate } from 'react-router-dom'
import { useSelector, useDispatch  } from 'react-redux'
import {logout, reset} from '../features/auth/authSlice'
import { createSoftware, reset as sReset } from '../features/software/softwareSlice'

function Header() {
    const navigate = useNavigate()
    const dispatch = useDispatch()
    const {user} = useSelector((state) => state.auth)

    const onLogout = () => {
        dispatch(logout())
        dispatch(reset())
        navigate('/')
    }

    return (
        <header className='header'>
            <div className='logo'>
                <Link to='/'>Software Jumbo</Link>
            </div>
            <ul>
                {user ? (
                        <ul className='hdrIn'>
                            <li>
                                <button className='btn' onClick={onLogout}><FaSignOutAlt /> Logout</button>
                            </li>
                            <li>
                                <Link to="/create-software" className="btn btn-reverse btn-block">
                                    <FaQuestionCircle /> Create A New Software Post
                                </Link>
                            </li>
                        </ul>
                ) : (
                    <>
                        <li>
                            <Link to='/login'>
                                <FaSignInAlt /> Login
                            </Link>
                        </li>
                        <li>
                            <Link to='/register'>
                                <FaUser /> Register
                            </Link>
                        </li>
                    </>
                )}
                
            </ul>
        </header>
    )
}

export default Header