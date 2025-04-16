const express = require('express')
const router = express.Router()
const {getSoftwares, getSoftware, createSoftware, deleteSoftware, updateSoftware} = require('../controllers/softwareController')

const {protect} = require('../middleware/authMiddleware')


router.route('/').get(protect, getSoftwares).post(protect, createSoftware)


router
.route('/:id')
.get(protect, getSoftware)
.delete(protect, deleteSoftware)
.put(protect, updateSoftware)


module.exports = router
