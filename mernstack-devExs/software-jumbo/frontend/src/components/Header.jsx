import {FaSignInAlt, FaSignOutAlt, FaUser, FaAlignLeft} from 'react-icons/fa'
import { Link, useNavigate } from 'react-router-dom'
import { useSelector, useDispatch  } from 'react-redux'
import {logout, reset} from '../features/auth/authSlice'
import { createSoftware, reset as sReset } from '../features/software/softwareSlice'
import { MoreOptions } from './MoreOptions'

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
            <section className="heading">
                <h1>Welcome to the world of Software</h1>
            </section>
            <ul>
                {user ? (
                        <>
                            <ul className='SignedInHdr'>
                                <li className='more-options-li'>
                                    <button className='btn' onClick={onLogout}><FaAlignLeft /> More Options</button>
                                    <MoreOptions optionShow={true}/>
                                    
                                </li>
                                <li>
                                    <button className='btn' onClick={onLogout}><FaSignOutAlt /> Logout</button>
                                </li>
                            </ul>
                        </>
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