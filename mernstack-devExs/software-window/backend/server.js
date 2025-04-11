const express = require('express')
const dotenv = require('dotenv').config()
const connectDB = require('./config/db')
const PORT = process.env.PORT || 5000

connectDB()

const app = express()

app.use(express.json())
app.use(express.urlencoded({ extended: false }))

app.get('/', (req, res) => {
    res.status(200).json({ message: 'Browse for All the software in the world!'})
})

app.listen(PORT, () => console.log(`Server Started on port ${PORT}`))