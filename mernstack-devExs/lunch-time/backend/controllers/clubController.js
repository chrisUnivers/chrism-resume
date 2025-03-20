const User = require('../models/userModel')
const Club = require('../models/clubModel')

// @desc Get user clubs
// @route GET /api/clubs
// @access Private

const getClubs = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        const clubs = await Club.find({user: req.user.id})
        res.status(200).json(clubs)
        // res.status(200).json({ message: 'Get club'})
    } catch (error) {
        console.error('Login User error')
        next(error)
    }
}

// @desc   Get user club
// @route  GET /api/clubs/:id
// @access Private
const getClub = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        // const club = await Club.find({user: req.user.id})
        const club = await Club.findById(req.params.id)
        
        if(!club) {
            res.status(404)
            throw new Error('Club not found')
        }

        if (club.user.toString() != req.user.id) {
            res.status(401)
            throw new Error('Not Authorized')
        }
        res.status(200).json(club)
        // res.status(200).json({ message: 'Get club'})
    } catch (error) {
        console.error('getClub error')
        next(error)
    }
}

// @desc   Delete user club
// @route  DELETE /api/clubs/:id
// @access Private
const deleteClub = async (req, res, next) => {
    try {

        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        // const club = await Club.find({user: req.user.id})
        const club = await Club.findById(req.params.id)
        
        if(!club) {
            res.status(404)
            throw new Error('Club not found')
        }

        if (club.user.toString() != req.user.id) {
            res.status(401)
            throw new Error('Not Authorized')
        }

        await club.deleteOne()
        res.status(200).json({ success: true })
        // res.status(200).json({ message: 'Get club'})
    } catch (error) {
        console.error('deleteClub error')
        next(error)
    }
}

// @desc   Update user club
// @route  PUT /api/clubs/:id
// @access Private
const updateClub = async (req, res, next) => {
    try {
        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        // const club = await Club.find({user: req.user.id})
        const club = await Club.findById(req.params.id)
        
        if(!club) {
            res.status(404)
            throw new Error('Club not found')
        }

        if (club.user.toString() != req.user.id) {
            res.status(401)
            throw new Error('Not Authorized')
        }

        const updatedClub = await Club.findByIdAndUpdate(req.params.id, req.body, { new: true })
        
        res.status(200).json(updatedClub)
        // res.status(200).json({ message: 'Get club'})
    } catch (error) {
        console.error('deleteClub error')
        next(error)
    }
}

// @desc Create new club
// @route POST /api/club
// @access Private
const createClub = async (req, res, next) => {
    try {
        const {club, description} = req.body

        if(!club || !description) {
            res.status(400)
            throw new Error('Please add a description of the club')
        }

        const user = await User.findById(req.user.id)

        if(!user) {
            res.status(401)
            throw new Error('User not found')
        }

        const clubPost = await Club.create({
            user: req.user.id,
            club,
            description,
            status: 'new'
        })
        
        // 201 for create response
        res.status(201).json(clubPost)
    } catch (error) {
        console.error('Login User error')
        next(error)
    }
}

module.exports = {
    getClubs,
    getClub,
    createClub,
    deleteClub,
    updateClub,
}