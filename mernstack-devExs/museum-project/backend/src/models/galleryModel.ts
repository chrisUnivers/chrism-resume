 import { model, Schema } from "dynamoose";


const showcaseSchema = new Schema ({
    showcaseId: {
        type: String,
        required: true,
    },
    artId: {
        type: String,
        required: true,
    },
    artDescription: {
        type: String,
        required: true,
    },
    artistId: {
        type: String,
        required: true,
    },

    artistName: {
        type: String,
        required: true,
    },
    artImage: {
        type: String,
        required: true,
    },
    showcaseDateAndTime: {
        type: String,
        required: true,
    },
    status: {
        type: String,
        required: true,
        enum: ["Upcoming", "Open", "Closed"],
    }
});

const gallerySchema = new Schema({
    galaId: {
        type: String,
        required: true,
    },
    galaAddress: {
        type: String,
        required: true,
    },
    galaName: {
        type: String,
        required: true,
    },
    galaShowcases: {
        type: Array,
        schema: [showcaseSchema],
    },
},{
    timestamps: true,
  }
);

const GalleryEvent = model("GalleryEvent", gallerySchema);
export default GalleryEvent;