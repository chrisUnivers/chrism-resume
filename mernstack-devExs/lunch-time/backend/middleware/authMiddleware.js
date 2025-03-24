const jwt = require('jsonwebtoken')
const User = require('../models/userModel')

const protect = async (req, res, next) => {
    try {
        let token

        if(req.headers.authorization && req.headers.authorization.startsWith('Bearer')) {
            try {
                // Get token from Header
                token = req.headers.authorization.split(' ')[1]
                // Verify token
                const decoded = jwt.verify(token, process.env.JWT_SECRET)
                // Get user from token
                req.user = await User.findById(decoded.id).select('-password')

                next()
            } catch (tkError) {
                console.log(tkError)
                res.status(401)
                throw new Error('Not authorized')
            }
        }

        if (!token) {
            res.status(401)
            throw new Error('Token not valid')
        }
    } catch (error) {
        console.error('Not authorized Bad error!')
        next(error)
    }
}

const notprotect = async (req, res, next) => {
    try {
        let notToken
        try {
            next()
        } catch (ntError) {
            console.log("not protect middleware")
        }
    } catch (error) {
        console.log("not protect middleware no token")
    }
}

module.exports = { protect, notprotect }