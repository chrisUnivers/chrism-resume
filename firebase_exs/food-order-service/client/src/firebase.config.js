import { initializeApp } from "firebase/app";
import {getFirestore} from 'firebase/firestore'

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyCQnKQnzIA1Ocg81tWBbV5ohRaCpgoKueI",
  authDomain: "food-ordering-service-ad6bb.firebaseapp.com",
  projectId: "food-ordering-service-ad6bb",
  storageBucket: "food-ordering-service-ad6bb.firebasestorage.app",
  messagingSenderId: "17360541266",
  appId: "1:17360541266:web:89c90f5ec9a68aec2d718b"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
export const db = getFirestore()