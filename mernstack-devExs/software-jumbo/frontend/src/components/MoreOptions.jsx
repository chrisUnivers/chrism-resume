import { Link} from 'react-router-dom'
import { FaQuestionCircle, FaWeibo } from "react-icons/fa";

const openClose = () => {
    setOptionShow(!optionShow)
}

export const MoreOptions = (optionToggles) => {
    const {optionShow, setOptionShow } = optionToggles;

    return (
        <>
            <div className={optionShow ? "moreoptions-items" : "moreoptions-hidden"} >
                <Link to="/create-software" className="btn btn-reverse btn-block option-item">
                    <FaWeibo /> Create A New Software Post
                </Link>
                <Link to="/create-software" className="btn btn-reverse btn-block option-item">
                    <FaWeibo /> Create A New Software Post
                </Link>
                <Link to="/create-software" className="btn btn-reverse btn-block option-item">
                    <FaWeibo /> Create A New Software Post
                </Link>
            </div>
        </>
    )
}