import { useEffect, useState } from "react"
import { useSelector, useDispatch } from "react-redux"
import { getPublicClubs, reset } from "../features/clubs/clubSlice"
import Spinner from "../components/Spinner"
import BackButton from "../components/BackButton"
import ClubPost from "../components/ClubPost"

function PublicClubs() {
    const user = null
    const { clubs, isLoading, isSuccess } = useSelector((state) => state.clubs)

    const dispatch = useDispatch()

    useEffect(() => {
        return () => {
            if(isSuccess) {
                dispatch(reset())
            }
        }
    }, [dispatch, isSuccess])

    useEffect(() => {
        dispatch(getPublicClubs())
    }, [dispatch])

    if(isLoading) {
        return <Spinner />
    }
    
    return (
        <>
            <div className="back-btn">
                <BackButton url='/' />
            </div>
            <h1>Active Clubs</h1>
            <div className="clubposts">
                <div className="clubpost-headings">
                    <div>Date</div>
                    <div>Club</div>
                    <div>Status</div>
                    <div></div>
                </div>
                {console.log(clubs)}
                {clubs.map((club) => (
                    <ClubPost key={club._id} clubpost={club} userId={user ? user._id : null}/>
                ))}
            </div>
        </>
    )
}

export default PublicClubs