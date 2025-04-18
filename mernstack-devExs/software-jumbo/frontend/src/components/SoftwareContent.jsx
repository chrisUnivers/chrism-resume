import { Link } from "react-router-dom"


function SoftwareContent({softwareId, userId}) {
    return (
        <div className="software-info">
            <img className="software-bg" src={`/assets/software_svg/firebase_${software.imageurl}.svg`}/>
            <div className="software-info-content">
                <div>{software.softwarename}</div>
                <div className={`status status-${software.status}`}>
                    {software.status}
                </div>
            </div>
            <div className="software-description">
                {software.description}
            </div>
            {(userId != null) && (userId === software.user) && 
                <Link to={`/create-software`} className='btn btn-reverse btnbwsm'>Edit Software</Link>
            }

        </div>
    )
}

export default SoftwareContent

{/* <div className="softwares">
    <SoftwareContent key={software._id} software={software} userId={user._id}  className="software-item software-expanded"/>
    {console.log("use passed in info", params.softwareId)}
</div> */}
