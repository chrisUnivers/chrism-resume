import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import clubService from './clubService'

const initialState = {
    clubs: [],
    club: {},
    isError: false,
    isSuccess: false,
    isLoading: false,
    message: '',
}

// Create new clubs
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

// Get user clubs
export const getClubs = createAsyncThunk('clubs/getAll', 
    async (_, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await clubService.getClubs(token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Get public clubs
export const getPublicClubs = createAsyncThunk('clubs/getPublic', 
    async (_, thunkAPI) => {
        try {
            return await clubService.getPublicClubs()
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Get user club
export const getClub = createAsyncThunk('clubs/get', 
    async (clubId, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await clubService.getClub(clubId, token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Close club
export const closeClub = createAsyncThunk('clubs/close', 
    async (clubId, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await clubService.closeClub(clubId, token)
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
        .addCase(getClubs.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getClubs.fulfilled, (state, action) => {
            state.isLoading = false
            state.isSuccess = true
            state.clubs = action.payload
        })
        .addCase(getClubs.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(getClub.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getClub.fulfilled, (state, action) => {
            state.isLoading = false
            state.isSuccess = true
            state.club = action.payload
        })
        .addCase(getClub.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(getPublicClubs.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getPublicClubs.fulfilled, (state, action) => {
            state.isLoading = false
            state.clubs = action.payload
        })
        .addCase(getPublicClubs.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(closeClub.fulfilled, (state, action) => {
            state.isLoading = false
            state.clubs.map((club) => club._id === action.payload._id ? (club.status = 'closed') : club) 
        })
    },
})

export const { reset } = clubSlice.actions
export default clubSlice.reducer