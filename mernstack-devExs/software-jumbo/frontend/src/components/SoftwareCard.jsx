import { Link } from "react-router-dom"


function SoftwareCard({software, fetchedSoftware}) {
    
    return (
        <div className="software-card">
            <Link to={`/software/${software._id}`} className='btn btn-reverse-sm sw-link'>
                <img className="software-bg" src={fetchedSoftware != null && fetchedSoftware.softwarename == 'mongo cloud' ? fetchedSoftware.imgUrls[0] : `/assets/software_svg/firebase_${software.imageurl}.svg`}/>
                <div className="software-label"> 
                    <div className="software-name"> {software.softwarename} </div>
                    <div className="software-status">{software.status}</div>
                </div>
                
            </Link>
        </div>
    )
}

export default SoftwareCard