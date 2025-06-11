import express, { Request, Response } from "express";
import bodyParser from "body-parser";
import dotenv from "dotenv";
import * as dynamoose from "dynamoose";
import cors from "cors"


dotenv.config()
const app = express()
app.use(express.json())
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cors());

const isProduction = process.env.NODE_ENV === "production";


if (!isProduction) {
  dynamoose.aws.ddb.local()
}


app.get("/", (req, res) => {
  res.send("This is home route");
});

const port =  process.env.PORT || 3000;
app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});
