import { Request, Response } from "express";
import GalleryModel from "../models/galleryModel";

export  const listAllShowcases = async(
    req: Request,
    res: Response
): Promise<void> => {
    const { vibe } = req.query;
    try {
        const showcases = vibe && vibe !== "all" ? await GalleryModel.scan("vibe").eq(vibe).exec() : GalleryModel.scan().exec()
        res.json({message: "Showcases retrived successfully", data: showcases })
    } catch (error) {
        res.status(500).json({ message: "Problem retrievinng showcases", error});
    }
}

export const getShowcase = async(
    req: Request,
    res: Response
): Promise<void> => {
    const { showcaseId } = req.params;
    try {
        const showcase = await GalleryModel.get(showcaseId);
        if (!showcase) {
            res.status(404).json({ message: "Showcase not found"});
            return;
        }

        res.json({message: "Showcase retrived successfully", data: showcase })
    } catch (error) {
        res.status(500).json({ message: "Problem retrievinng showcase", error});
    }
};