"use client";

import Link from 'next/link'
import React from 'react'
import { FaSearch } from 'react-icons/fa';

const WelcomeHomeNavbar = () => {
  return (
    <nav className="w-full flex justify-center bg-gray-100">
        <div className="flex justify-between items-center w-3/4 py-8">
          <div className="flex justify-between items-center gap-14">
            <Link href="/" className="font-bold text-lg sm:text-xl hover:text-gray-200">Art Showcases</Link>
            <div className="flex items-center gap-4">
              <div className="relative group">
                  <Link href="/search" className="bg-gray-700 pl-10 sm:pl-14 pr-6 sm:pr-20 py-3 sm:py-4 rounded-xl text-white text-sm sm:text-base">
                      <span className="hidden sm:inline">Find Artists and Showcases</span>
                      <span className="sm:hidden">Find All</span>
                  </Link>
                  <FaSearch className="absolute left-3 sm:left-5 top-1/2 transform -translate-y-1/2 text-gray-300 transition-all duration-300"/>
              </div>
            </div>
          </div>
        
          <div className="flex items-center gap-2 sm:gap-4">
            {/* signIn */}
          </div>
        </div>
    </nav>
  )
}

export default WelcomeHomeNavbar