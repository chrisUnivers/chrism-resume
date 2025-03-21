import axios from 'axios'

const API_URL = '/api/clubs/'

// Create new club
const createClub = async (clubData, token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }

    const response = await axios.post(API_URL, clubData, config)

    return response.data
}

const clubService = {
    createClub,
}

export default clubService