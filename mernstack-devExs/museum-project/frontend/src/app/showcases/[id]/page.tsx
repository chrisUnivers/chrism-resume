"use client";


import React, { useState } from 'react'
import ShowcaseHeader from '../ShowcaseHeader';

type Props = {
    params: {id: string}
}

const Showcase = ({params}: Props) => {
    const { id } = params;
    const [activeTab, setActiveTab] = useState("Board");
  
    return (
    <div>Showcase</div>
    // <ShowcaseHeader activeTab={activeTab} setActiveTab={setActiveTab} />
  )
}

export default Showcase