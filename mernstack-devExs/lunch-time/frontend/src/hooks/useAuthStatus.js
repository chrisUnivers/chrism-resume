import { useState, useEffect } from "react";
import { useSelector } from "react-redux";


export const useAuthStatus = () => {
    const [loggedIn, setLoggedIn] = useState(false)
    const [loading, setLoading] = useState(true)

    // get user from the state
    const {user} = useSelector((state) => state.auth) // Note the **state** we need here for the authorized user is in the features/auth directory(see authSlice)

    useEffect(() => {
        if(user) {
            setLoggedIn(true)
        } else {
            setLoggedIn(false)
        }
        setLoading(false)
    }, [user])

    return { loggedIn, loading }
}