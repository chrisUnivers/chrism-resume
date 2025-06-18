import { model, Schema } from "dynamoose";


const showcaseSchema = new Schema ({
    showcaseId: {
        type: String,
        required: true,
    },
    showcaseTitle: {
        type: String,
        required: true,
    },
    artId: {
        type: String,
        required: true,
    },
    description: {
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
    image: {
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
    },
    vibe: {
        type: String,
        required: true,
    },
},{
    timestamps: true,
  }
);

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

const ShowcaseModel = model("Showcase", showcaseSchema);
export default ShowcaseModel;