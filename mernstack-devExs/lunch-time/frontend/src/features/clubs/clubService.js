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

// Get user clubs
const getClubs = async (token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }

    const response = await axios.get(API_URL, config)

    return response.data
}

// Get public clubs
const getPublicClubs = async () => {
    const response = await axios.get(API_URL + 'activeclubs') 

    return response.data
}

// Get user clubs
const getClub = async (clubId, token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }

    const response = await axios.get(API_URL + clubId, config)

    return response.data
}

// Close club
const closeClub = async (clubId, token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }

    const response = await axios.put(API_URL + clubId, { status: 'closed' } , config)

    return response.data
}

const clubService = {
    createClub,
    getClubs,
    getClub,
    getPublicClubs,
    closeClub,
}

export default clubService