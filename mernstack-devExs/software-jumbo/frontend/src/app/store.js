import { configureStore } from '@reduxjs/toolkit';
import authReducer from '../features/auth/authSlice';
import softwareSlice from '../features/software/softwareSlice'

const store = configureStore({
    reducer: {
        auth: authReducer,
        softwarestate: softwareSlice,
    },
});


export default store