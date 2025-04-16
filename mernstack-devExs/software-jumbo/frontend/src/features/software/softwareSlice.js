import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import softwareService from "./softwareService";

const initialState = {
    softwares: [],
    software: {},
    isError: false,
    isSuccess: false,
    isLoading: false,
    message: '',
}

// Create new softwares
export const createSoftware = createAsyncThunk('softwares/create', 
    async (softwareData, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await softwareService.createSoftware(softwareData, token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Get user softwares
export const getSoftwares = createAsyncThunk('softwares/getAll', 
    async (_, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await softwareService.getSoftwares(token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)


// Get user software
export const getSoftware = createAsyncThunk('softwares/get', 
    async (softwareId, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await softwareService.getSoftware(softwareId, token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Get home page softwares
export const getPublicSoftwares = createAsyncThunk('softwares/getPublic', 
    async (_, thunkAPI) => {
        try {
            return await softwareService.getPublicSoftwares()
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Remove software
export const removeSoftware = createAsyncThunk('softwares/remove', 
    async (softwareId, thunkAPI) => {
        try {
            const token = thunkAPI.getState().auth.user.token
            return await softwareService.removeSoftware(softwareId, token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

export const softwareSlice = createSlice({
    name: 'software',
    initialState,
    reducers: {
        reset: (state) => initialState
    },
    extraReducers: (builder) => {
        builder
        .addCase(createSoftware.pending, (state) => {
            state.isLoading = true 
        })
        .addCase(createSoftware.fulfilled, (state) => {
            state.isLoading = false
            state.isSuccess = true
        })
        .addCase(createSoftware.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(getSoftwares.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getSoftwares.fulfilled, (state, action) => {
            state.isLoading = false
            state.isSuccess = true
            state.softwares = action.payload
        })
        .addCase(getSoftwares.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(getSoftware.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getSoftware.fulfilled, (state, action) => {
            state.isLoading = false
            state.isSuccess = true
            state.software = action.payload
        })
        .addCase(getSoftware.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(getPublicSoftwares.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getPublicSoftwares.fulfilled, (state, action) => {
            state.isLoading = false
            state.softwares = action.payload
        })
        .addCase(getPublicSoftwares.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(removeSoftware.fulfilled, (state, action) => {
            state.isLoading = false
            state.softwares.map((software) => software._id === action.payload._id ? (software.status = 'removed') : software) 
        })
    },
})

export const { reset } = softwareSlice.actions
export default softwareSlice.reducer