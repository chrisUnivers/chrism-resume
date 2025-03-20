const express = require('express')
const router = express.Router()
const {getClubs, getClub, createClub, deleteClub, updateClub} = require('../controllers/clubController')

const {protect} = require('../middleware/authMiddleware')

router.route('/').get(protect,getClubs).post(protect, createClub)

router
.route('/:id')
.get(protect, getClub)
.delete(protect, deleteClub)
.put(protect, updateClub)

module.exports = router