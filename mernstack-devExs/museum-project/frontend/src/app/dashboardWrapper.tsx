"use client"

import React from 'react'
import Navbar from "@/components/Navbar";
import Sidebar from '@/components/Sidebar';
import StoreProvider, { useAppSelector } from './redux';
import AuthProvider from './authProvider';


const DashboardLayout = ({ children }: {children: React.ReactNode}) => {
  const isSidebarCollapsed = useAppSelector((state) => state.global.isSidebarCollapsed);
  return (
    <div className="flex min-h-screen w-full bg-gray-50 text-gray-900">
      {/** sidebar element */}
      <Sidebar />
      <main className={`flex w-full flex-col bg-blue-300 dark:bg-gray-950 ${isSidebarCollapsed ? "" : "md:pl-64"}`}>
        {/** navbar */}
        <Navbar />
        {children}
      </main>
    </div> 
  );
};

const DashboardWrapper = ({ children }: { children: React.ReactNode }) => {
  
  return (
    <StoreProvider>
      <AuthProvider>
        <DashboardLayout>{children}</DashboardLayout>  
      </AuthProvider>
      {/* <DashboardLayout>{children}</DashboardLayout> */}
    </StoreProvider>
  )
}

export default DashboardWrapper;