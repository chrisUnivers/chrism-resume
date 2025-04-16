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
        },
        description: {
            type: String,
            required: [true, 'Provide a description for this software.'],
            default: '',
        },
        status: {
            type: String,
            required: true,
            enum: ['Beta', 'LTS', 'New Update', 'Archived'],
            default: 'LTS'
        },
        imageurl: {
            type: String,
            required: true,
            enum: ['machine', 'analytics', 'distribution', 'functions'],
            default: '',
        } // use firebase for uploading images.
    },
    {
        timestamps: true,
    }
)

module.exports = mongoose.model('Software', softwareSchema)