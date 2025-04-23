import { useState, useEffect } from "react"
import { useSelector, useDispatch } from "react-redux"
import { getAllSoftwares, reset } from "../features/software/softwareSlice"
import { collection, getDocs, query, where, orderBy, limit, startAfter } from 'firebase/firestore'
import { db } from '../firebase.config'
import SoftwareCard from "../components/SoftwareCard"
import Spinner from "../components/Spinner"


function Home() {
    const { softwares, isLoading, isSuccess } = useSelector((state) => state.softwarestore)

    const [fetchedSoftware, setSoftwares] = useState(null)
    
    const dispatch = useDispatch()
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

    useEffect(() => {
        const fetchSoftwares = async () => {
            try {
                
                const softwareRef = collection(db, 'softwares')

                // Create a query
                const q = query(softwareRef, orderBy('timestamp', 'desc'), limit(10))

                // Executye query
                const querySnap = await getDocs(q)

                const softwares = []

                querySnap.forEach((doc) => {
                    // console.log(doc.data())
                    return softwares.push({
                        id: doc.id,
                        data: doc.data()
                    })
                })
                // console.log(softwares[0])
                setSoftwares(softwares[0])
            } catch (error) {
                console.log('Could not fetch softwares')
            }
        }
        fetchSoftwares()
    })

    if(isLoading) {
        return <Spinner />
    }
    

    return (
        <>
            <div className="softwares">
                {softwares.map((software) => (
                    <SoftwareCard key={software._id} software={software} className="software-item"/>
                ))}
                {
                    fetchedSoftware != null && fetchedSoftware.data.imgUrls != null && (
                        <div className="software-card">
                            <img className="software-bg" src={fetchedSoftware.data.imgUrls[0]} />
                        </div>
                    )
                }                
            </div>
        </>
    )
}

export default Home

// {softwares.map((software) => (
//     <SoftwareCard key={software._id} software={software} fetchedSoftware={fetchedSoftware != null ? fetchedSoftware.data : ''}  className="software-item"/>
// ))}