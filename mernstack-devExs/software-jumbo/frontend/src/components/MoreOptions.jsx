import { Link} from 'react-router-dom'
import { FaQuestionCircle, FaWeibo } from "react-icons/fa";

const openClose = () => {
    setOptionShow(!optionShow)
}

export const MoreOptions = (optionToggles) => {
    const {optionShow, setOptionShow } = optionToggles;

    return (
        <>
            <div className="moreoptions-items" >
                <Link to="/create-software" className="btn btn-block">
                    <FaWeibo /> Create A New Software Post
                </Link>
            </div>
        </>
    )
}