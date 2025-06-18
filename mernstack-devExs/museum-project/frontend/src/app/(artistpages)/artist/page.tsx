"use client";


import { useGetAuthUserQuery } from '@/state/api';
import React from 'react'



const Artist = () => {
  const { data: currentUser } = useGetAuthUserQuery({});
  console.log(currentUser?.user);
  
  return (
    <></>
  )
}

export default Artist