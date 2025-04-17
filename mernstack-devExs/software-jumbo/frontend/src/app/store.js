import { configureStore } from '@reduxjs/toolkit';
import authReducer from '../features/auth/authSlice';
import softwareReducer from '../features/software/softwareSlice'

const store = configureStore({
    reducer: {
        auth: authReducer,
        softwarestore: softwareReducer,
    },
});


export default store