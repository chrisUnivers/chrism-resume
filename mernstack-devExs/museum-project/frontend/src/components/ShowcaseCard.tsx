import Image from 'next/image'
import React from 'react'

const ShowcaseCard = ({
    showcase,
    isSelected,
    onClick
}: ShowcaseCardProps) => {
  return (
    <div onClick={onClick} className={` bg-gray-900 overflow-hidden rounded-lg  flex flex-col cursor-pointer border-2 h-full${isSelected ? "border-indigo-300" : " border-transparent"}`}>
      ShowcaseCard
      <div className="relative w-auto pt-[56.25%]">
        <Image src={showcase.image || "/tokyoAndyokohama.png"} alt={showcase.showcaseTitle} fill sizes="(max-width: 768px) 100vw, (max-width: 1200px) 50vw, 33vw" className="object-cover transition-transform" />
      </div>
      <div className="course-card-search__content">
        <div>
          <h2 className="course-card-search__title">{showcase.showcaseTitle}</h2>
          <p className="course-card-search__description">
            {showcase.description}
          </p>

        </div>
        <div className="mt-2">
          <p className="text-gray-400 text-sm">By {showcase.artistName}</p>
          <div className="flex justify-between items-center mt-1">
            <span className="text-indigo-300 font-semibold"> {showcase.status}</span>
          </div>
        </div>
      </div>
    </div>
  )
}

export default ShowcaseCard