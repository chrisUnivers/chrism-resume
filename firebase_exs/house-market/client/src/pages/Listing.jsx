import { useState, useEffect } from "react"
import { Link, useNavigate, useParams } from "react-router-dom"
import SwiperCore, {Navigation, Pagination, Scrollbar, A11y} from 'swiper'
import { Swiper, SwiperSlide } from 'swiper/react'
import 'swiper/swiper-bundle.css'
import { getDoc, doc } from "firebase/firestore"
import { getAuth } from "firebase/auth"
import {db} from '../firebase.config'
import Spinner from '../components/Spinner'
import shareIcon from '../assets/svg/shareIcon.svg'
SwiperCore.use([Navigation, Pagination, Scrollbar, A11y])


function Listing() {
    const [listing, setListing] = useState(null)
    const [loading, setLoading] = useState(true)
    const [shareLinkCopied, setShareLinkCopied] = useState(false)

    const navigate = useNavigate()
    const params = useParams()
    const auth = getAuth()

    useEffect (() => {
        const fetchListing = async () => {
            const docRef = doc(db, 'listings', params.listingId)
            const docSnap = await getDoc(docRef)

            if(docSnap.exists()) {
                console.log(docSnap.data());
                setListing(docSnap.data())
                setLoading(false)
            }
        }

        fetchListing()
    }, [navigate, params.listingId])

    if (loading) {
        return <Spinner />
    }

    return (
        <main>
            {/* <Swiper slidesPerView={1} pagination={{clickable: true}}>
                {listing.imgUrls.map((url, index) => (
                    <SwiperSlide key={index}>
                        <div style={{background: `url(${listing.imgUrls[index]}) center no-repeat`, backgroundSize: 'cover',}} className='swiperSlideDiv'>

                        </div>
                    </SwiperSlide>
                ))}
            </Swiper> */}


            <div className="shareIconDiv" onClick={() => {
                navigator.clipboard.writeText(window.location.href) 
                setShareLinkCopied(true)
                setTimeout(() => {
                    setShareLinkCopied(false)
                }, 2000)
            }}>
                <img src={shareIcon} align=''/>
            </div>

            {shareLinkCopied && <p className="linkCopied">Copied!</p>}

            <div className="listingDetails">
                <p className="listingName">{listing.name} - ${listing.offer ? listing.discountedPrice.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ','): listing.regularPrice.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',')}</p>
                <p className="listingLocation">{listing.location}</p>
                <p className="listingType">For {listing.type === 'rent' ? 'Rent': 'Sale'}</p>
                {listing.offer && (
                    <p className="discountPrice">${listing.regularPrice - listing.dicountedPrice} discount</p>
                )}

                <ul className="listingDetailsList">
                    <li>
                        {listing.bedrooms > 1 ? `${listing.bedrooms} Bedrooms` : "1 Bedroom"}
                    </li>
                    <li>
                        {listing.bathrooms > 1 ? `${listing.Bathrooms} Bathroom` : "1 Bathroom"}
                    </li>
                    <li>{listing.parking && "Parking Spot"}</li>
                    <li>{listing.furnished && "Furnished"}</li>
                </ul>

                <p className="ListingLocationTitle">Location</p>

                {auth.currentUser?.uid !== listing.userRef && (
                    <Link to={`/contact/${listing.userRef}?listingName=${listing.name}&listingLocation=${listing.location}`} className="primaryButton">Contact Landlord</Link>
                )}
            </div>

        </main>
    )
}

export default Listing