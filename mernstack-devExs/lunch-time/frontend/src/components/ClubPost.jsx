import { Link } from "react-router-dom"


function ClubPost({clubpost, userId}) {
    return (
        <div className="clubpost">
            <div>{new Date(clubpost.createdAt).toLocaleString('en-Us')}</div>
            <div>{clubpost.club}</div>
            <div className={`status status-${clubpost.status}`}>{clubpost.status}</div>
            <Link to={`/club/${clubpost._id}`} className='btn btn-reverse btnbwsm'>View Club</Link>
            {(userId === clubpost.user) && <Link to={`/`} className='btn btn-reverse btnbwsm'>Edit Club</Link>}
        </div>
    )
}

export default ClubPost