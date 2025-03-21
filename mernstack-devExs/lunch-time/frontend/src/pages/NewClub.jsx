import { useState, useEffect } from "react"
import { useSelector, useDispatch } from "react-redux"
import { useNavigate } from "react-router-dom"
import { toast } from "react-toastify"
import { createClub, reset } from "../features/clubs/clubSlice"
import Spinner from "../components/Spinner"
import BackButton from "../components/BackButton"


function NewClub() {
    const {user} = useSelector((state) => state.auth)
    const {isLoading, isError, isSuccess, message} = useSelector((state) => state.clubs)

    const [name] = useState(user.name)
    const [email] = useState(user.email)
    
    const [club, setClub] = useState('Math')
    const [description, setDescription] = useState(user.description)
    const [clubCreated, setClubCreated] = useState(false)

    const dispatch = useDispatch()
    const navigate = useNavigate()

    useEffect(() => {
        if(isError) {
            toast.error(message)
        }

        if(isSuccess && clubCreated) {
            dispatch(reset())
            navigate('/clubs')
        }

        dispatch(reset())
    }, [dispatch, isError, isSuccess, navigate, message])
    
    const onSubmit = (e) => {
        e.preventDefault()
        setClubCreated(true) // prevents empty clubs from being created
        dispatch(createClub({ club, description }))
        if(isLoading) {
            return <Spinner />
        }
    }

    return (
        <>
            {/* {console.log(name)} */}
            <div className="back-btn">
                <BackButton url='/' />
            </div>
            <div className="heading">
                <h1>Create New Club</h1>
                <p>Please fill out the form below</p>
            </div>
                <div className="form">
                    <div className="form-group">
                        <label htmlFor="name">Name to use</label>
                        <input type="text" className="form-control" value={name} disabled />
                    </div>
                    <div className="form-group">
                        <label htmlFor="name">Email to use</label>
                        <input type="text" className="form-control" value={email} disabled />
                    </div> 
                    <form onSubmit={onSubmit}>
                        <div className="form-group">
                            <label htmlFor="club">Club</label>
                            <select name="club" id="club" value={club} onChange={(e) => setClub(e.target.value)}>
                                <option value="math">Math Club</option>
                                <option value="biology">Biology Club</option>
                                <option value="chess">Chess Club</option>
                                <option value="chemistry">Chemistry Club</option>
                                <option value="physics">Physics Club</option>
                            </select>
                        </div>
                        <div className="form-group">
                            <label htmlFor="description">Description of the club</label>
                            <textarea name="description" id="description"className="form-control" placeholder="Description" value={description} onChange={(e) => setDescription(e.target.value)}></textarea>
                        </div>
                        <div className="form-group">
                            <button className="btn btn-block">Submit</button>
                        </div>
                    </form>
            </div>
        </>
    )
}

export default NewClub