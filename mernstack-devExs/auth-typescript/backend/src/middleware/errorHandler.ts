import { ErrorRequestHandler} from "express";
// import { INTERNAL_SERVER_ERROR } from "../constants/http";

const errorHandler: ErrorRequestHandler = (error, req, res, next) => {
    console.log(`PATH ${req.path}`, error);
  
    return res.status(500).send("Internal server error");
};

export default errorHandler; 