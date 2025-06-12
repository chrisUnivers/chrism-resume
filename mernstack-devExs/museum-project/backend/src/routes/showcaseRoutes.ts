import express from "express"
import { createShowcase, getShowcase, listAllShowcases } from "../controllers/showcaseController";

const router = express.Router();

router.route("/").get(listAllShowcases).post(createShowcase); // post request(edit button) only shown when signed in userId === selected showcaseArtistId
router.get("/:showcaseId", getShowcase);

export default router;