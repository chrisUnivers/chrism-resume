"use client";

import React from 'react'
import StoreProvider, { useAppSelector } from './redux';
import HomepageLayout from './(notartistpages)/layout';
import AuthProvider from './authProvider';


const HomepageWrapper = ({ children }: { children: React.ReactNode }) => {
    return (
    <StoreProvider>
      <AuthProvider>
        {children}
      </AuthProvider>
    </StoreProvider>
  )
}

export default HomepageWrapper;