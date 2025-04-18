import {FaSignInAlt, FaSignOutAlt, FaUser, FaNodeJs} from 'react-icons/fa'
import { Link, useNavigate } from 'react-router-dom'
import { useSelector, useDispatch  } from 'react-redux'
import {logout, reset} from '../features/auth/authSlice'
import { createSoftware, reset as sReset } from '../features/software/softwareSlice'
import { MoreOptions } from './MoreOptions'

function NavBar() {
    // const navigate = useNavigate()
    // const dispatch = useDispatch()
    // const {user} = useSelector((state) => state.auth)

    return (
        <>
                <nav className='navbar'>
                    <ul className='navbar-items'>
                        <li className='navbar-item'>
                            <Link to="/create-software">
                                Coding Software
                            </Link>
                        </li>
                        <li className='navbar-item'>
                            <Link to="/create-software">
                                Graphics Software
                            </Link>
                        </li>
                        <li className='navbar-item'>
                            <Link to="/create-software">
                                UX Software
                            </Link>
                        </li>
                        <li className='navbar-item'>
                            <Link to="/create-software">
                                Movie Studio Software
                            </Link>
                        </li>
                        <li className='navbar-item'>
                            <Link to="/create-software">
                                Music Creation Software
                            </Link>
                        </li>
                    </ul>            
                </nav>
        </>
    )
}

export default NavBar