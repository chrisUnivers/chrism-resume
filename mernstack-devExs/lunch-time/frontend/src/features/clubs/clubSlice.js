import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import clubService from './clubService'

const initialState = {
    // for multiple clubs
    clubs: [],
    // for a single club
    club: {},
    isError: false,
    isSuccess: false,
    isLoading: false,
    message: '',
}

// Create new club
export const createClub = createAsyncThunk('clubs/create', 
    async (clubData, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await clubService.createClub(clubData, token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

export const clubSlice = createSlice({
    name: 'club',
    initialState,
    reducers: {
        reset: (state) => initialState
    },
    extraReducers: (builder) => {
        builder
        .addCase(createClub.pending, (state) => {
            state.isLoading = true 
        })
        .addCase(createClub.fulfilled, (state) => {
            state.isLoading = false
            state.isSuccess = true
        })
        .addCase(createClub.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
    },
})

export const { reset } = clubSlice.actions
export default clubSlice.reducer