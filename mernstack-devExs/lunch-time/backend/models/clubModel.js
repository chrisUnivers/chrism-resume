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
            required: [true, 'Please select a subject'],
            enum: ['math', 'biology', 'chemistry', 'physics', 'chess'],
        },
        clubname: {
            type: String,
            required: [true, 'Please enter the name of you club'],
            default: 'before-names'
        },
        clubtype: {
            type: String,
            required: [true, 'Set visibility options'],
            default: 'public',
            enum: ['private', 'public']
        },
        description: {
            type: String,
            required: [true, 'Please enter a description today\'s itinerary.'],
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