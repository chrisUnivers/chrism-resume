import React from 'react'

type Props = {
    activeTab: string;
    setActiveTab: (tabName: string) => void
};

const ShowcaseHeader = ({activeTab, setActiveTab}: Props) => {

    return (
    <div className="px-4 xl:px-6">
        ShowcaseHeader
        <div className="pb-6 pt-6 lg:pb-4 lg:pt-8">
            
        </div>
    </div>
  )
}

export default ShowcaseHeader