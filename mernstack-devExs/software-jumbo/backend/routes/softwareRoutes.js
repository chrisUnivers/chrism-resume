const express = require('express')
const router = express.Router()
const {getSoftwares, getSoftware, getSoftwareOut, getAllSoftwares, createSoftware, deleteSoftware, updateSoftware} = require('../controller/softwareController')

const {protect} = require('../middleware/authMiddleware')


router.route('/').get(protect, getSoftwares).post(protect, createSoftware)


router.route('/softwares/all').get(getAllSoftwares)
router.route('/:id/0').get(getSoftwareOut)

// router.route('/softwares').get(getSoftwares)
router
.route('/:id')
.get(protect, getSoftware)
.delete(protect, deleteSoftware)
.put(protect, updateSoftware)


module.exports = router
