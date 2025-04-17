import axios from 'axios'

const API_URL = '/api/software/'

// Create new software
const createSoftware = async (softwareData, token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }
    const response = await axios.post(API_URL, softwareData, config)
    return response.data
}

// Get all user software
const getSoftwares = async (token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }
    const response = await axios.get(API_URL, config)
    return response.data
}

// Get user software
const getSoftware = async (softwareId, token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }

    const response = await axios.get(API_URL + softwareId, config)

    return response.data
}

// Get home page softwares
const getAllSoftwares = async () => {
    const response = await axios.get(API_URL + 'softwares/all') 

    return response.data
}

// Remove software(meaning full if purchased and now returned)
const removeSoftware = async (softwareId, token) => {
    const config = {
        headers: {
            Authorization: `Bearer ${token}`,
        },
    }

    const response = await axios.put(API_URL + softwareId, { status: 'removed' } , config)

    return response.data
}

const softwareService = {
    createSoftware,
    getSoftwares,
    getSoftware,
    removeSoftware,
    getAllSoftwares,
}

export default softwareService