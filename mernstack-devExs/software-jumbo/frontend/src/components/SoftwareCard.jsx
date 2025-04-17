import { Link } from "react-router-dom"


function SoftwareCard({software}) {
    
    return (
        <div className="software-card">
            <img className="software-bg" src={`/assets/software_svg/firebase_${software.imageurl}.svg`}/>
            <div className="software-label">
                <Link to={`/software/${software._id}`} className='btn btn-reverse-sm'>{software.softwarename}</Link>
                <div className="software-status">{software.status}</div>
            </div>
        </div>
    )
}

export default SoftwareCard