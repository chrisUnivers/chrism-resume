import { Link } from "react-router-dom"


function SoftwareCard({software}) {
    
    return (
        <div className="software-card">
            <img className="software-bg" src={software.imgUrl}/>
            <div className={`status status-${software.status}`}>{software.status}</div>
            <Link to={`/software/${software._id}`} className='btn btn-reverse-sm'>{software.softwarename}</Link>
        </div>
    )
}

export default SoftwareCard