"use client";

import Navbar from "@/components/Navbar";
import Sidebar from "@/components/Sidebar";
import { useAppSelector } from "../redux";



export default function ArtistLayout({ children }: {children: React.ReactNode}) {
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
}