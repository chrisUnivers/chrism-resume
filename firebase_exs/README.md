## Purpose
  * This repository contains a react-vite project for listing house markets. To added a listing, one must be signed in. However, the code for creating a listing in is `house-market/client/pages/CreateListing.jsx`. All other pages are reachable once the app is running.
  * The project used firebase and firestore for cloud storage. Basically, to handle user logins and store the listings made.
  * Mostly works as intended with exception to to the Swiper components. The swiper component causes issues most likely due to version used. Ignoring for now.
  * Firebase and firestore work with no problems
  * The project is based off a udemy course.
    + https://www.udemy.com/course/react-front-to-back-2022

## How to run
  * Use the command below once in the `house-market/client` directory.
    + npm run dev