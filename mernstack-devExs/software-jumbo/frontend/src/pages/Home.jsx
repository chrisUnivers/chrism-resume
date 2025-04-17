import { useState, useEffect } from "react"
import { useSelector, useDispatch } from "react-redux"
import { getAllSoftwares, reset } from "../features/software/softwareSlice"
import SoftwareCard from "../components/SoftwareCard"
import Spinner from "../components/Spinner"


function Home() {
    const { softwares, isLoading, isSuccess } = useSelector((state) => state.softwarestore)
    
    const dispatch = useDispatch()
    const { user } = useSelector((state) => state.auth)
    const [name] = useState(user.name);
    useEffect(() => {
        return () => {
            if(isSuccess) {
                dispatch(reset())
            }
        }
        // eslint-disable-next-line
    }, [isSuccess])

    useEffect(() => {
        dispatch(getAllSoftwares())
    }, [dispatch])

    if(isLoading) {
        return <Spinner />
    }
    

    return (
        <>
            <div className="softwares">
                {softwares.map((software) => (
                    <SoftwareCard key={software._id} software={software}  className="software-item"/>
                ))}
            </div>
            
        </>
    )
}

export default Home