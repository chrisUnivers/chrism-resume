import { Request, Response } from "express";
import ShowcaseModel from "../models/showcaseModel";
import { v4 as uuidv4 } from "uuid";

export  const listAllShowcases = async(
    req: Request,
    res: Response
): Promise<void> => {
    const { vibe } = req.query;
    try {
        const showcases = vibe && vibe !== "all" ? await ShowcaseModel.scan("vibe").eq(vibe).exec() : ShowcaseModel.scan().exec()
        res.json({message: "Showcases retrived successfully", data: showcases })
    } catch (error) {
        res.status(500).json({ message: "Problem retrievinng showcases", error});
    }
}

export const getShowcase = async( req: Request, res: Response): Promise<void> => {
    const { showcaseId } = req.params;
    try {
        const showcase = await ShowcaseModel.get(showcaseId);
        if (!showcase) {
            res.status(404).json({ message: "Showcase not found"});
            return;
        }

        res.json({message: "Showcase retrived successfully", data: showcase })
    } catch (error) {
        res.status(500).json({ message: "Problem retrievinng showcase", error});
    }
};

export const createShowcase = async( req: Request, res: Response): Promise<void> => {
    const { artistName, description, vibe } = req.body;
    try { // showcaseId artId description artistId artistName image showcaseDateAndTime status vibe
        const newShowcase = new ShowcaseModel({
            showcaseId: uuidv4(),
            artId: uuidv4(),
            description: "",
            artistId: uuidv4(),
            artistName,
            image: "",
            status: "Upcoming",
            vibe,
        });
        await newShowcase.save();

        res.json({message: "Showcase retrived successfully", data: newShowcase })
    } catch (error: any) {
        res.status(500).json({ message: `Problem creating showcase: ${error.message}`});
    }
};

export const updateShowcase = async( req: Request, res: Response): Promise<void> => {
    const { showcaseId } = req.params;
    const newData = { ...req.body };
    try { // showcaseId artId description artistId artistName image showcaseDateAndTime status vibe
        const showcase = await ShowcaseModel.get(showcaseId);
        if (!showcase) {
            res.status(404).json({ message: "Showcase not found. Check provided infromation"});
            return;
        }

        // if (showcase.artistId !== artistId) {
        //     res.status(403).json({ message: "Not authorized to update showcase"});
        // }
        
        res.json({message: "Showcase updated successfully" })
    } catch (error: any) {
        res.status(500).json({ message: `Problem updating showcase: ${error.message}`});
    }
};