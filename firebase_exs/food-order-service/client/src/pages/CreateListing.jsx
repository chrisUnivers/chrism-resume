import { useState, useEffect, useRef } from 'react'
import { getAuth, onAuthStateChanged } from 'firebase/auth'
import { useNavigate } from 'react-router-dom'
import Spinner from '../components/Spinner'

function CreateListing() {
    
    const [geolocationEnabled, setGeolocationEnable] = useState(false)
    const [loading, setLoading] = useState(false)
    const [formData, setFormData] = useState({
        type: 'pastry',
        name: '',
        parking: false,
        takeout: true,
        address: '',
        offer: false,
        regularPrice: 0,
        discountedPrice:0,
        images: {},
        latitude: 0,
        longitude: 0
    })

    const {type,name,parking,takeout,address,offer,regularPrice,discountedPrice,images,latitude,longitude} = formData

    const auth = getAuth()
    const navigate = useNavigate()
    const isMounted = useRef(true)

    useEffect(() => {
        if(isMounted) {
            onAuthStateChanged(auth, (user) => {
                if(user) {
                    setFormData({...formData, userRef: user.uid})
                } else {
                    navigate('/sign-in')
                }
            })
        }

        return () => {
            isMounted.current = false
        }
        // eslingt-disable-next-line react-hooks/exhaustive-deps
    }, [isMounted])

    const onSubmit = async (e) => {
        e.preventDefault()
        
        setLoading(true)

        if(discountedPrice >= regularPrice)
        {
            setLoading(false)
            console.log('Discounted price needs to be less than regular price')
            return
        }

        if(images.length > 6) {
            setLoading(false)
            console.log('Max of 6 images')
            return
        }

        let geolocation = {}
        let location 

        // Need to paste API key after the equal sign in the geocode link below
        if(geolocationEnabled) {
            const response = await fetch(`https://maps.googleapis.com/maps/api/geocode/json?address=${address}&key=${ProcessingInstruction.env.REACT_APP_GEOCODE_API_KEY}`)

            const data = await response.json()

            geolocation.lat = data.results[0]?.geometry.location.lat ?? 0
            geolocation.lng = data.results[0]?.geometry.location.lng ?? 0
            location = data.status === 'ZERO_RESULTS' ? undefined : data.results[0]?.formatted_address

            if(location === undefined || location.includes('undefined')) {
                setLoading(false)
                console.log('Need valid address')
            }
        } else {
            geolocation.lat = latitude
            geolocation.lng = longitude
            location = address
        }

        setLoading(false)
    }

    const onMutate = (e) => {
        let boolean = null

        if(e.target.value === 'true') {
            boolean = true
        }

        if(e.target.value === 'false') {
            boolean = false
        }

        // Files
        if(e.target.files) {
            setFormData((prevState) => ({
                ...prevState,
                images: e.targe.files
            }))
        }
        // Text/Booleans/Numbers
        if(!e.target.files) {
            setFormData((prevState) => ({
                ...prevState,
                [e.target.id]: boolean ?? e.target.value,
            }))
        }
    }

    if (loading) {
        return <Spinner />
    }

    return (
        <div className="profile">
            <header>
                <p className="pageHeader">Add New Product</p>
            </header>

            <main>
                <form onSubmit={onSubmit}>
                    <label className="formLabel">Name</label>
                    <input className="formInputName" type="text" id="name" value={name} onChange={onMutate} maxLength="32" minLength="10" required/>

                    <div className="formRooms flex">
                        <div>
                            <label className="formLabel">Quantity</label>
                            <input className="formInputSmall" type="number" id="quantity" value={name} onChange={onMutate} min="1" max="50" required/>
                        </div>
                    </div>

                    <label className="formLabel">Parking</label>
                    <div className="formButtons">
                        <button className={parking ? "formButtonActive" : "formButton"} type="button" id="parking" value={true} onClick={onMutate} min="1"max="50"
                        >Yes</button>
                        <button className={!parking && parking !== null ? "formButtonActive" : "formButton"} type="button" id="parking" value={false}onClick={onMutate} >No</button>
                    </div>
                    <label className="formLabel">Takeout</label>
                    <div className="formButtons">
                        <button className={takeout ? "formButtonActive" : "formButton"}type="button" id="takeout" value={true} onClick={onMutate}>Yes</button>
                        <button className={!takeout && takeout !== null ? "formButtonActive" : "formButton"} type="button" id="furnished" value={false} onClick={onMutate}>No</button>
                    </div>

                    <label className="formLabel">Address</label>
                    <textarea className="formInputAddress" type="text" id="address" value={address}onChange={onMutate} required/>
                    
                    {!geolocationEnabled && (
                        <div className="formLatLng flex">
                            <div>
                                <label className="formLabel">Latitude</label>
                                <input className="formInputSmall" type="number" id="latitude" value={latitude} onChange={onMutate}
                                required/>
                            </div>
                            <div>
                                <label className="formLabel">Longitude</label>
                                <input className="formInputSmall" type="number" id="longitude" value={longitude} onChange={onMutate} required/>
                            </div>
                        </div>
                    )}
                    <label className="formLabel">Offer</label>
                    <div className="formButtons">
                        <button className={offer ? "formButtonActive" : "formButton"}type="button" id="offer" value={true}onClick={onMutate}>Yes</button>
                        <button className={!offer && offer !== null ? "formButtonActive" : "formButton"} type="button" id="offer" value={false} onClick={onMutate}>No</button>
                    </div>

                    <label className="formLabel">Regular Price</label>
                    <div className="formPriceDiv">
                        <input className="formInputSmall" type="number" id="regularPrice" value={regularPrice} onChange={onMutate}min="50" max="750000000" required/>{type === "rent" && <p className="formPriceText">$ / Month</p>}
                    </div>

                    {offer && (
                        <>
                            <label className="formLabel">Discounted Price</label>
                            <input className="formInputSmall" type="number" id="discountedPrice" value={discountedPrice} onChange={onMutate} min="50" max="750000000" required={offer}/>
                        </>
                    )}    
                    <label className="formLabel">Images</label>
                    <p className="imagesInfo">The first image will be the cover (max 6).</p>
                    <input className="formInputFile" type="file" id="images" onChange={onMutate}max="6" accept=".jpg,.png,.jpeg" multiple required/>
                    <button type="submit" className="primaryButton createListingButton">Add New Product</button>
                </form>
            </main>
        </div>
    )
}

export default CreateListing