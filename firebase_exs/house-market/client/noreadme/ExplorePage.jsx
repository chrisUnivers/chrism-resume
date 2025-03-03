import { Link } from 'react-router-dom'
import rentCategoryImage from '../assets/jpg/rentCategoryImage.jpg'
import sellCategoryImage from '../assets/jpg/sellCategoryImage.jpg'
import goodieBakery from '../assets/jpg/comuffins.png'
import goodieWraps from '../assets/jpg/chipotles.png'

function Explore() {
    return (
        <div className='explore'>
            <header>
                <p className='pageHeader'>Explore</p>
            </header>

            <main>
                <p className='exploreCategoryHeading'>Categories</p>
                <div className='exploreCategories'>
                    <Link to='/category/rent'>
                        <img src={goodieWraps} alt='rent' className='exploreCategoryImg'/>
                        <p className='exploreCategoryName'>Wrap and More</p>
                    </Link>
                    <Link to='/category/sale'>
                        <img src={goodieBakery} alt='sell' className='exploreCategoryImg'/>
                        <p className='exploreCategoryName'>Baked Goods</p>
                    </Link>
                </div>
            </main>
        </div>
    )
}

export default Explore