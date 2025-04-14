const mongoose = require('mongoose')

const softwareSchema = mongoose.Schema(
    {
        user: {
            type: mongoose.Schema.Types.ObjectId,
            required: true,
            ref: 'User'
        },
        softwarename: {
            type: String,
            required: [true, 'Please enter the name of you software'],
            default: 'before-names'
        },
        description: {
            type: String,
            required: [true, 'Provide a description for this software.'],
        },
        status: {
            type: String,
            required: true,
            enum: ['Beta', 'LTS', 'New Update', 'Archived'],
            default: 'Beta'
        }
    },
    {
        timestamps: true,
    }
)

module.exports = mongoose.model('Software', softwareSchema)