import {FaQuestionCircle, FaTicketAlt} from 'react-icons/fa'
import { Link } from 'react-router-dom'
import { useSelector } from 'react-redux'
import Header from './Header'

function SideBarNav() {
    const {user} = useSelector((state) => state.auth)

    return (
        <>
            <div className='sidebar'>
                <Header />
                {user ? (
                    <>
                        <ul className='sidebarin'>
                            <li>
                                <Link to="/new-club" className="btn btn-reverse btn-block">
                                    <FaQuestionCircle /> Create New Club
                                </Link>
                            </li>
                            <li>
                                <Link to="/my-clubs" className="btn btn-block">
                                    <FaTicketAlt /> See My Clubs
                                </Link>
                            </li>
                            <li>
                                <Link to="/clubs" className="btn btn-block">
                                    <FaTicketAlt /> See Active Clubs
                                </Link>
                            </li>
                        </ul>
                    </>
                ) : (
                    <ul className='sidebarout'>
                        <li>
                            <Link to="/clubs" className="btn btn-block">
                                <FaTicketAlt /> See Active Clubs
                            </Link>
                        </li>
                    </ul>
                )}
                
            </div>
        </>
        
    )
}

export default SideBarNav