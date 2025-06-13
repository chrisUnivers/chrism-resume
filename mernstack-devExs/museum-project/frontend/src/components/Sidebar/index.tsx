"use client";


import React, { useState } from 'react'
import Image from 'next/image';
import { FaArchway, FaCity, FaGear, FaLock, FaShieldHeart, FaX } from 'react-icons/fa6';
import { IconType } from 'react-icons';
import { usePathname } from 'next/navigation';
import { useAppDispatch, useAppSelector } from '@/app/redux';
import Link from 'next/link';
import { setIsSidebarCollapsed } from '@/state';
import { FaChevronDown, FaChevronUp, FaConciergeBell, FaHome } from 'react-icons/fa';
import { useGetShowcasesQuery } from '@/state/api';

const Sidebar = () => {
    const [showArtShowcases, setShowArtShowcases] = useState(true);
    const [showActions, setShowActions] = useState(true); // local state
    
    const { data: showcases} = useGetShowcasesQuery();
    const dispatch = useAppDispatch();
    const isSidebarCollapsed = useAppSelector( (state) => state.global.isSidebarCollapsed,);
    
    
    const sidebarClassNames = `fixed flex flex-col h-[100%] justify-between shadow-xl transition-all duration-300 h-full z-40 dark:bg-black overflow-y-auto bg-white ${isSidebarCollapsed ? "w-0 hidden" : "w-72"}`;
    
    return ( <div className={sidebarClassNames}>
      <div className="flex h-[100%] w-full flex-col justify-start">
          <div className="z-50 flex min-h-[56px] w-72 items-center justify-between bg-white px-6 pt-3 dark:bg-black">
            <div className="text-xl font-bold text-gray-800 dark:text-white">
              The Museum Project
            </div>
            {isSidebarCollapsed ? null : (
              <button className="py-3" onClick={() => {dispatch(setIsSidebarCollapsed(!isSidebarCollapsed)); }}>
                <FaX className="h-6 w-6 text-gray-800 hover:text-gray-500 dark:text-white" />
              </button>
            )}
          </div> 
          {/* DASHBOARD */}
          <div className="flex items-center gap-5 border-y-[1.5px] border-gray-200 px-8 py-4 dark:border-gray-700">
            <Image
              src="/window.svg"
              alt="Logo"
              width={40}
              height={40}
            />
            <div>
              <h3 className="text-md font-bold tracking-wide dark:text-gray-200">
                Art Showcase Menu!
              </h3>
              <div className="mt-1 flex items-start gap-2">
                <FaLock className="mt-[0.1rem] h-3 w-3 text-gray-500 dark:text-gray-400" />
                <p className="text-xs text-gray-500">Private</p>
              </div>
            </div>
          </div>
          <nav className="z-10 w-full">
            <SidebarLink icon={FaHome} label="Home" href="/" />
            <SidebarLink icon={FaArchway} label="Art Museums" href="/artmuseum" /> 
            <SidebarLink icon={FaCity} label="Art Galas" href="/artgalas" />
            <SidebarLink icon={FaGear} label="Settings" href="/settings" />
          </nav>
        
          {/* MY ART SHOWCASES LINKS*/}
          <button onClick={() => setShowArtShowcases((prev) => !prev)}className="flex w-full items-center justify-between px-8 py-3 text-gray-500">
            <span className="">My Art Showcases</span> {showArtShowcases ? (
              <FaChevronUp className="h-5 w-5" />
            ) : ( <FaChevronDown className="h-5 w-5" /> )}
          </button>
          {/* MY ART SHOWCASES LISTS*/}
          {showArtShowcases && showcases?.map((showcase) => (
            <SidebarLink key={showcase.showcaseId} icon={FaShieldHeart} label={showcase.description} href={`/showcases/${showcase.showcaseId}`} />
          ))}


          {/* ACTIONS LINKS*/}
          <button onClick={() => setShowActions((prev) => !prev)}className="flex w-full items-center justify-between px-8 py-3 text-gray-500">
            <span className="">Actions</span> {showActions ? (
              <FaChevronUp className="h-5 w-5" />
            ) : ( <FaChevronDown className="h-5 w-5" /> )}
          </button>
          {showActions && (
            <>
              <SidebarLink icon={FaConciergeBell} label="Invites" href="/actions/invites" />
            </>
          )}
      </div>
    </div>);
};

interface SidebarLinkProps {
  href: string;
  icon: IconType;
  label: string;
}

const SidebarLink = ({
  href,
  icon: Icon,
  label,
}: SidebarLinkProps) => {
  const pathname = usePathname();
  const isActive =
  pathname === href || (pathname === "/" && href === "/dashboard");

  return (
    <Link href={href} className="w-full">
      <div className={`relative flex cursor-pointer items-center gap-3 transition-colors hover:bg-gray-100 dark:bg-black dark:hover:bg-gray-700 ${ isActive ? "bg-gray-100 text-white dark:bg-gray-600" : ""} justify-start px-8 py-3`}>
        {isActive && ( <div className="absolute left-0 top-0 h-[100%] w-[5px] bg-blue-200" />
        )}
        <Icon className="h-6 w-6 text-gray-800 dark:text-gray-100" />
        <span className={`font-medium text-gray-800 dark:text-gray-100`}>
          {label}
        </span>
      </div>
    </Link>
  )
}

export default Sidebar