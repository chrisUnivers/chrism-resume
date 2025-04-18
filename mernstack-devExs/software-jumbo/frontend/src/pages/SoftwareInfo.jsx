import { useEffect, useState } from "react"
import { useParams, useNavigate } from "react-router-dom"
import { toast } from "react-toastify"
import { useSelector, useDispatch } from "react-redux"
import { getSoftware, getSoftwareOut } from "../features/software/softwareSlice"
import BackButton from "../components/BackButton"
import SoftwareCard from "../components/SoftwareCard"
import Spinner from "../components/Spinner"


function SoftwareInfo() {
    const {user} = useSelector((state) => state.auth)
    const {software, isError, message} = useSelector((state) => state.softwarestore)

    const dispatch = useDispatch()
    const { softwareId } = useParams()
    const [LoggedIn, setLoggedIn] = useState(false)
    useEffect(() => {
        if(isError) {
            toast.error(message)
        }
        
        console.log("not logged in", user)
        if (user) {
            setLoggedIn(true)
            dispatch(getSoftware(softwareId))
        } else {
            console.log("else")
            dispatch(getSoftwareOut(softwareId))
        }
        // eslint-disable-next-line
    }, [isError, message, softwareId])

    if(isError) {
        return <h3>Something Went Wrong</h3>
    }

    return (
        <>
            <div className="softwareinfo">
                <div className="softwareheader">
                    <div className="software-info-id">
                        <h3>
                            Software Name: {software.softwarename}
                            <span className={`status status-${software.status}`}> {software.status}
                            </span>
                        </h3>
                        <img className="software-bg" src={`/assets/software_svg/firebase_${software.imageurl}.svg`}/>
                    </div>
                    <div className="software-info-desc">
                        <h3>Software description</h3>
                        <p>{software.description}</p>
                        <h3>Date created: {new Date(software.createdAt).toLocaleString('en-US')}</h3>
                    </div>
                    {!LoggedIn && (
                        <div className="software-actions">
                            <div className="back-btn software-actions-item">
                                <BackButton url="/" />
                            </div>
                            <button className="btn btn-block software-actions-item">Edit</button>
                        </div>
                    )}
                </div>
            </div>
        </>
    )
}

export default SoftwareInfo