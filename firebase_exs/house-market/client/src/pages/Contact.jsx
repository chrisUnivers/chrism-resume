import {useState, useEffect} from 'react'
import { useParams, useSearchParams } from 'react-router-dom'
import { doc, getDoc } from 'firebase/firestore'
import {db} from '../firebase.config'

function Contact() {
    const [message, setMessage] = useState('')
    const [landlord, setLandlord] = useState(null)
    const [searchParams, setSearchParams] = useSearchParams()

    const params = useParams()

    useEffect(() => {
        const getLandlord = async () => {
            const docRef = doc(db, 'users', params.landlordId)
            const docSnap = await getDoc(docRef)

            if (docSnap.exists()) {
                setLandlord(docSnap.data())
            } else {
                console.log('Could not get landlord data')
            }
        }

        getLandlord()
    }, [params.landlordId])

    const onChange = (e) => setMessage(e.targe.value)

    return <div className='pageContainer'>
        <header>
            <p className='pageHeader'>Contact Landlord</p>
        </header>

        {landlord !== null && (
            <main>
                <div className='contactLandlord'>
                    <p className='landlordName'>Contact {landlord?.name}</p>
                </div>

                <form action="" className="messageForm">
                    <div className="messageDiv">
                        <label htmlFor="message" className="messageLabel">Message</label>
                        <textarea name="message" id="message" className='textarea' value={message} onChange={onChange}></textarea>
                    </div>

                    {/* might be a good idea to also add this message to a message collections in the database and then the person receiving this email could instead have those emails waiting from, him or her, when they login in */}
                    <a href={`mailto:${landlord.email}?Subject=${searchParams.get('listingName')}&body=${message}`}>
                        <button className='primaryButton'>Send Message</button>
                    </a>
                </form>
            </main>
        )}
    </div>
}

export default Contact
// swiper installation: npm install swiper or npm install swiper@6.8.1
