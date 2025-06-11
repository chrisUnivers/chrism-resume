import express from "express"
import { getShowcase, listAllShowcases } from "../controllers/showcaseController";

const router = express.Router();

router.get("/", listAllShowcases);
router.get("/:showcaseId", getShowcase);

export default router;