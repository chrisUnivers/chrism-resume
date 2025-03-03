import {Link} from 'react-router-dom'
import DeleteIcon from '../assets/svg/deleteIcon.svg?react'
import bedIcon from '../assets/svg/bedIcon.svg'
import bathtubIcon from '../assets/svg/bathtubIcon.svg'

function ListingItem({ listing, id, onDelete}) {
    return (
        <li className='categoryListing'>
            <Link to={`/category/${listing.type === 'pastry' ? 'rent' : listing.type}/${id}`} className='categoryListingLink'>
                <img src={listing.imgUrls[0]} alt={listing.name} className='categoryListingImg' />
                <div className='categoryListingDetails'>
                    <p className='categoryListingLocation'>
                        {listing.location}
                    </p>
                    <p className='categoryListingName'>{listing.name}</p>
                    <p className='categoryListingPrice'>
                        ${listing.offer ? listing.discountedPrice.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',') : listing.regularPrice.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',')}
                    </p>
                    
                </div>
            </Link>

            {onDelete &&
                <DeleteIcon className='removeIcon' fill='()rgb(231, 76, 60)' onClick={() => onDelete(listing.id, listing.name)}/>}
        </li>
    )
}

export default ListingItem