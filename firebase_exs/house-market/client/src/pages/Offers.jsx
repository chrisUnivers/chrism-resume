import { useEffect, useState } from 'react'
import { useParams } from 'react-router-dom'
import { collection, getDocs, query, where, orderBy, limit, startAfter } from 'firebase/firestore'
import { db } from '../firebase.config'
import Spinner from '../components/Spinner'
import ListingItem from '../components/ListingItem'

function Offers() {
    const [listings, setListings] = useState(null)
    const [loading, setLoading] = useState(true)

    const params = useParams()

    useEffect(() => {
        const fetchListings = async () => {
            try {
                // Get reffence
                const listingsRef = collection(db, 'listings')

                // Create a query
                const q = query(listingsRef, where('offer', '==', true), orderBy('timestamp', 'desc'), limit(10))

                // Executye query
                const querySnap = await getDocs(q)

                const listing = []

                querySnap.forEach((doc) => {
                    // console.log(doc.data())
                    return listing.push({
                        id: doc.id,
                        data: doc.data()
                    })
                })
                setListings(listing)
                setLoading(false)
            } catch (error) {
                console.log(error)
            }
        }
        fetchListings()
    }, [])
    
    return <div className='categoty'>
        <header>
            <p className="pageHeader">
                Offers
            </p>
        </header>

        {loading ? (<Spinner />) : listings && listings.length > 0 ? (
            <>
                <main>
                    <ul className='categoryListings'>
                        {listings.map((listing) => (
                            <ListingItem listing={listing.data} id={listing.id} key={listing.id}/>
                        ))}
                    </ul>
                </main>
            </>) : (<p>There are no current offers</p>) }
    </div>
}

export default Offers