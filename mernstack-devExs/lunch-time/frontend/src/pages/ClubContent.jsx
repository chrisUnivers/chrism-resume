import { useEffect, useState } from "react"
import { useParams, useNavigate } from "react-router-dom"
import { toast } from "react-toastify"
import { FaPlus } from "react-icons/fa"
import { useSelector, useDispatch } from "react-redux"
import { getClub, closeClub } from "../features/clubs/clubSlice"
import BackButton from "../components/BackButton"
import Spinner from "../components/Spinner"

{/* Add support for asking questions */}
const customStyles = {
    content: {
        width: '600px',
        top: '50%',
        left: '50%',
        right: 'auto',
        bottom: 'auto',
        marginRight: '-50%',
        transform: 'translate(-50%, -50%)',
        position: 'relative',
    },
}


function ClubContent() {

    const {club, isLoading, isSuccess, isError, message} = useSelector((state) => state.clubs)

    const params = useParams()
    const navigate = useNavigate()
    const dispatch = useDispatch()
    const { clubId } = useParams()

    useEffect(() => {
        if(isError) {
            toast.error(message)
        }
        
        dispatch(getClub(clubId))
        // eslint-disable-next-line
    }, [isError, message, clubId])

    
    const onClubClose = () => {
        dispatch(closeClub(clubId))
        toast.success('Club Closed')
        navigate('/clubs')
    }

    if(isError) {
        return <h3>Something Went Wrong</h3>
    }

    return (
        <>
            <div className="back-btn">
                <BackButton url="/clubs" />
            </div>
            <div className="clubinfo">
                <div className="clubheader">
                    <div className="club-info-id">
                        <h2>
                            Club Name: {club.clubname}
                            <span className={`status status-${club.status}`}>
                                {club.status}
                            </span>
                        </h2>
                        <h3>Club: {club.club}</h3>
                        <h3>Date created: {new Date(club.createdAt).toLocaleString('en-US')}</h3>
                    </div>
                    <div className="club-info-desc">
                        <h3>Club description</h3>
                        <p>{club.description}</p>
                    </div>
                </div>

                {club.status !== 'closed' && (
                    <button onClick={onClubClose}className="btn btn-block btn-danger">Close Club</button>
                )}
            </div>
        </>
    )
}

export default ClubContent