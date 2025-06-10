
import { useAppDispatch, useAppSelector } from '@/app/redux';
import { setIsSidebarCollapsed } from '@/state';
import Link from 'next/link';
import React from 'react'
import { FaBars, FaSearch } from 'react-icons/fa';
import { FaGear } from 'react-icons/fa6';


const Navbar = () => {
  const dispatch = useAppDispatch();
  const isSidebarCollapsed = useAppSelector(
    (state) => state.global.isSidebarCollapsed,
  );
  return (
    <div className={`flex items-center justify-between bg-white ${isSidebarCollapsed ? "px-4" : "px-12"} py-3 dark:bg-black`}>
        {/* Search Bar */}
        <div className="flex items-center gap-8">
          {!isSidebarCollapsed ? null : (
            <button onClick={() => dispatch(setIsSidebarCollapsed(!isSidebarCollapsed))}>

              <FaBars className="h-8 w-8 dark:text-white" />
            </button>
          )}
          <div className="relative flex h-min w-[200px]">
              <FaSearch className="absolute left-[4px] top-1/2 mr-2 h-5 w-5 -translate-y-1/2 transform cursor-pointer dark:text-white"/>
              <input className="w-full rounded border-none bg-gray-100 p-2 pl-8 placeholder-gray-500 focus:border-transparent focus:outline-none dark:bg-gray-700 dark:text-white dark:placeholder-white" type="search" placeholder="Search..."/>
          </div>
        </div>

        {/* Icons */}
        <div className="flex items-center">
          <Link href="/settings" className="h-min w-min rounded p-2 hover:bg-gray-100">

            <FaGear className="h-6 w-6 cursor-pointer dark:text-white"/>
          </Link>
          <div className="ml-2 mr-5 hidden min-h-[2em] w-[0.1rem] bg-gray-200 md:inline-block"></div>
        </div>
    </div>
  );
}

export default Navbar