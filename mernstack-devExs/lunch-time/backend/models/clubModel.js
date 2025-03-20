const mongoose = require('mongoose')

const clubSchema = mongoose.Schema(
    {
        user: {
            type: mongoose.Schema.Types.ObjectId,
            required: true,
            ref: 'User'
        },
        club: {
            type: String,
            required: [true, 'Please select a club'],
            enum: ['Math Club', 'Biology Club', 'Chess Club', 'Chemistry Club', 'Physics Club'],
        },
        description: {
            type: String,
            required: [true, 'Please enter a description today\'s itinerary.']
        },
        status: {
            type: String,
            required: true,
            enum: ['new', 'open', 'closed'],
            default: 'new'
        }
    },
    {
        timestamps: true,
    }
)

module.exports = mongoose.model('Club', clubSchema)