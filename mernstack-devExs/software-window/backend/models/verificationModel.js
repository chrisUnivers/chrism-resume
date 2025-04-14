const mongoose = require('mongoose')

const verificationCode = mongoose.Schema({
    userId: {
        ref: "User",
        type: mongoose.Schema.Types.ObjectId,
        required: true,
        index: true,
      },
      type: { 
        type: String, 
        required: true,
        default: 'PasswordReset',
        enum: ['PasswordReset']
    },
      createdAt: { type: Date, required: true, default: Date.now },
      expiresAt: { type: Date, required: true },
})

module.exports = mongoose.model('VerificationCode', verificationCode)