import "dotenv/config";
import connectDB from "./config/db";
import cors from "cors";
import express from 'express';
import { APP_ORIGIN, PORT } from "./constants/env";
import errorHandler from "./middleware/errorHandler";

const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(
    cors({
      origin: APP_ORIGIN,
      credentials: true,
    })
  );

app.get("/", 
    (req, res) => {
    res.status(200).json({
        status: "OK!",
    })
});

app.use(errorHandler);

app.listen(PORT, async () => {
    console.log(`Server started on port ${PORT}`);
    await connectDB();
});