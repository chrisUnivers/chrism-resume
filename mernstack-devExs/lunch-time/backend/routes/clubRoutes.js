const express = require('express')
const router = express.Router()
const {getClubs, getClub, getPublicClubs, createClub, deleteClub, updateClub} = require('../controllers/clubController')

const {protect} = require('../middleware/authMiddleware')


router.route('/').get(protect, getClubs).post(protect, createClub)
// router.route('/:private').get(protect,getClubs)
// router.route('/').get(getClubs).post(protect, createClub)

router.route('/activeclubs').get(getPublicClubs)

router
.route('/:id')
.get(protect, getClub)
.delete(protect, deleteClub)
.put(protect, updateClub)


module.exports = router