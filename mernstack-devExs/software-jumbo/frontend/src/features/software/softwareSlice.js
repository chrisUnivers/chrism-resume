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
export const createSoftware = createAsyncThunk('software/create', 
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
export const getSoftwares = createAsyncThunk('software/getAll', 
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
export const getSoftware = createAsyncThunk('software/get', 
    async (softwareId, thunkAPI) => {
        try {
            console.log("used token", thunkAPI)
            const token = thunkAPI.getState().auth.user.token
            
            return await softwareService.getSoftware(softwareId, token)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)


// Get softwareOut
export const getSoftwareOut = createAsyncThunk('software/less', 
    async (softwareId, thunkAPI) => {
        try {
            // console.log("used id", softwareId)
            
            return await softwareService.getSoftwareOut(softwareId)
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Get home page softwares
export const getAllSoftwares = createAsyncThunk('software/getAllSoftwares', 
    async (_, thunkAPI) => {
        try {
            return await softwareService.getAllSoftwares()
        } catch (error) {
            const message = (error.response && error.response.data && error.response.data.message) || error.message || error.toString()

            return thunkAPI.rejectWithValue(message)
        }
    }
)

// Remove software
export const removeSoftware = createAsyncThunk('software/remove', 
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
        }).addCase(getSoftwareOut.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getSoftwareOut.fulfilled, (state, action) => {
            state.isLoading = false
            state.isSuccess = true
            state.software = action.payload
        })
        .addCase(getSoftwareOut.rejected, (state, action) => {
            state.isLoading = false
            state.isError = true
            state.message = action.payload
        })
        .addCase(getAllSoftwares.pending, (state) => {
            state.isLoading = true
        })
        .addCase(getAllSoftwares.fulfilled, (state, action) => {
            state.isLoading = false
            state.softwares = action.payload
        })
        .addCase(getAllSoftwares.rejected, (state, action) => {
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
getSoftwareOut