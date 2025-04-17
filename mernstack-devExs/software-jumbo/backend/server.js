const express = require('express')
const dotenv = require('dotenv').config()
const connectDB = require('./config/db')
const { errorHandler } = require('./middleware/errorHandler')

const PORT = process.env.PORT || 5000


// Connect to database
connectDB()

const app = express()

app.use(express.json())
app.use(express.urlencoded({ extended: false }))

app.get('/', (req, res) => {
    res.status(200).json({ message: 'Browse for All the software in the world!'})
})

app.use('/api/users', require('./routes/userRoutes'))
app.use('/api/software', require('./routes/softwareRoutes'))

// Call last. Otherwise some errors will not be handled.
app.use(errorHandler)

app.listen(PORT, () => console.log(`Server Started on port ${PORT}`))