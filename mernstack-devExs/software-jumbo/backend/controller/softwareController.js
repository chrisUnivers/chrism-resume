const User = require('../models/userModel')
const Software = require('../models/softwareModel')

// @desc Get user softwares
// @route GET /api/softwares
// @access Private
const getSoftwares = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)
        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        const softwares = await Software.find({user: req.user.id})
        res.status(200).json(softwares)

    } catch (error) {
        console.error('Login User error')
        next(error)
    }
}

// @desc   Get user software
// @route  GET /api/softwares/:id
// @access Private
const getSoftware = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        const software = await Software.findById(req.params.id)
        
        if(!software) {
            res.status(404)
            throw new Error('Software not found')
        }

        if (software.user.toString() != req.user.id) {
            res.status(401)
            throw new Error('Not Authorized')
        }
        res.status(200).json(software)
        
    } catch (error) {
        console.error('getSoftware error')
        next(error)
    }
}

// @desc   Get all softwares
// @route  GET /api/all/softwares
// @access Private
const getAllSoftwares = async (req, res, next) => {
    try {
        const softwares = await Software.find({status: {$ne: 'Archived'}})
        res.status(200).json(softwares)
    } catch (error) {
        console.error('Home page softwares error')
        next(error)
    }
}

// @desc   Delete user Software
// @route  DELETE /api/Softwares/:id
// @access Private
const deleteSoftware = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        const software = await Software.findById(req.params.id)
        
        if(!software) {
            res.status(404)
            throw new Error('Software not found')
        }

        if (software.user.toString() != req.user.id) {
            res.status(401)
            throw new Error('Not Authorized')
        }

        await software.deleteOne()
        res.status(200).json({ success: true })
        
    } catch (error) {
        console.error('delete software error')
        next(error)
    }
}

// @desc   Update user softwars
// @route  PUT /api/softwarss/:id
// @access Private
const updateSoftware = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        const software = await Software.findById(req.params.id)
        
        if(!software) {
            res.status(404)
            throw new Error('Software not found')
        }

        if (software.user.toString() != req.user.id) {
            res.status(401)
            throw new Error('Not Authorized')
        }

        const updatedSoftware = await Software.findByIdAndUpdate(req.params.id, req.body, { new: true })
        
        res.status(200).json(updatedSoftware)
    } catch (error) {
        console.error('Software name error')
        next(error)
    }
}

// @desc Create new software
// @route POST /api/software
// @access Private
const createSoftware = async (req, res, next) => {
    try {

        const {softwarename, description, imageurl} = req.body
        if(!softwarename || !description) {
            res.status(400)
            throw new Error('Please add a software and a description of the software')
        }

        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }
        const newsoftware = await Software.create({
            user: req.user.id,
            softwarename,
            description,
            status: 'LTS',
            imageurl
        })
        res.status(201).json(newsoftware)
    } catch (error) {
        console.error(error)
        next(error)
    }
}

module.exports = {
    getSoftwares,
    getSoftware,
    createSoftware,
    deleteSoftware,
    updateSoftware,
    getAllSoftwares,
}