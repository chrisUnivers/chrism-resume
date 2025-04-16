import { useEffect } from "react"
import { useSelector, useDispatch } from "react-redux"
import { getAllSoftwares, reset } from "../features/software/softwareSlice"
import Spinner from "../components/Spinner"


function Home() {
    const { softwares, isLoading, isSuccess } = useSelector((state) => state.softwares)

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

    if(isLoading) {
        return <Spinner />
    }
    

    return (
        <>
            <section className="heading">
                <h1>Welcome to the world of Software</h1>
            </section>
            <h1>All The Softwares In The World</h1>
            <div className="softwares">
                <div className="software-headings">
                    <div>Date</div>
                    <div>Product</div>
                    <div>Status</div>
                    <div></div>
                </div>
                {softwares.map((software) => (
                    console.log(software),
                    <SoftwareCard key={software._id} software={software} />
                ))}
            </div>
            
        </>
    )
}

export default Home