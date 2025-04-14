const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken')

const User = require('../models/userModel')

const registerUser = async (req, res, next) => {
    try {
        const {name, email, password} = req.body
        if(!name){
            res.status(400)
            throw new Error('Please enter your name')
        }
        if (!email) {
            res.status(400)
            throw new Error('Please provide an email')
        }
        if (!password) {
            res.status(400)
            throw new Error('Please provide a password')
        }
        const userExists = await User.findOne({email})

        if(userExists) {
            res.status(400)
            throw new Error('User already exists')
        }

        const salt = await bcrypt.genSalt(10)
        const hashedPassword = await bcrypt.hash(password, salt)

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
    }
}

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
            throw new Error('Wrong Password or user name')
        }
        
    } catch (error) {
        console.error('Login User error')
        next(error)
    }
}

const resetPasswordRequest = async (req, res, next) => {
    try {
        const {email} = req.body
        const user = await User.findOne({email})

        const expires = new Date(Date.now() + 60 * 60 * 1000);
        const verificationCode = await VerificationCodeM.create({
            userId: user._id,
            type: "PassWordReset",
            expires
        });

        const url = `/password/reset?code=${verificationCode._id}&exp=${expires.getTime()}`;

        // const { error } = await sendMail

    } catch (error) {
        
    }
}

const getMe = async (req, res, next) => {
    try {
        const user = {
            id: req.user._id,
            email: req.user.email,
            name: req.user.name
        }
        
        res.status(200).json(user)
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
    resetPasswordRequest,
    loginUser,
    getMe,
}