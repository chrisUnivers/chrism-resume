import { createSlice, PayloadAction } from "@reduxjs/toolkit";


export interface initialStateTypes {
  isSidebarCollapsed: boolean;
}

const initialState: initialStateTypes = {
  isSidebarCollapsed: false,
};

export const globalSlice = createSlice({
  name: "global",
  initialState,
  reducers: {
    setIsSidebarCollapsed: (state, action: PayloadAction<boolean>) => { // we pass in true or false
      state.isSidebarCollapsed = action.payload; // pass in boolean that changes the state
    },
  },
  
});

export const { setIsSidebarCollapsed } = globalSlice.actions;
export default globalSlice.reducer;
