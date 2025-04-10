const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken')

const User = require('../models/userModel')

// @desc Register a new user
// @route /api/users
// @access Public
const registerUser = async (req, res, next) => {
    try {
        const {name, email, password} = req.body
        if(!name || !email || !password){
            res.status(400)
            throw new Error('Please include all fields')
        }
        const userExists = await User.findOne({email})

        if(userExists) {
            res.status(400)
            throw new Error('User already exists')
        }

        // Hash password
        const salt = await bcrypt.genSalt(10)
        const hashedPassword = await bcrypt.hash(password, salt)

        // Create user
        const user = await User.create({
            name,
            email,
            password: hashedPassword
        })

        if(user) {
            res.status(201).json({
                _id: user._id,
                name: user.name,
                email: user.email,
                token: generateToken(user._id),
            })
        } else {
            res.status(400)
            throw new error('Invalid user data')
        }
    } catch (error) {
        console.log('Register User Error')
        next(error)
        // process.exit(1)
    }
}

// @desc Register a new user
// @route /api/users/login
// @access Public
const loginUser = async (req, res, next) => {
    try {
        const {email, password} = req.body
        const user = await User.findOne({email})

        if(user && (await bcrypt.compare(password, user.password))) {
            res.status(200).json({
                _id: user._id,
                name: user.name,
                email: user.email,
                token: generateToken(user._id),
            })
        } else {
            res.status(401)
            throw new Error('Invalid credentials')
        }
        
        // res.send('Login Route')
    } catch (error) {
        console.error('Login User error')
        next(error)
    }
}

const generateToken = (id) => {
    return jwt.sign({ id }, process.env.JWT_SECRET, {
        expiresIn: '30d'
    })
}

module.exports = {
    registerUser,
    loginUser,
}