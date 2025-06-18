import Link from 'next/link'
import React from 'react'

const Welcome = () => {
  return (
    <div className="flex justify-between items-center mt-12 h-[500px] rounded-lg bg-gray-700">
        <div className="basis-1/2 px-16 mx-auto">
            <h1 className="text-4xl font-bold px-16 mb-4">The World's Art Showcases</h1>
            <p className="text-lg text-gray-400 px-18 mb-8">
                This is the list of showcase you can see. Showcase for all artists.
            </p>
            <div className="flex justify-between items-center w-fit px-18">
                <Link href="/artist">
                    <div className="pl-24 pr-24 ml-32 mr-16 bg-indigo-400 hover:bg-indigo-300 px-4 py-2 rounded-md">Artist's Page</div>
                </Link>
            </div>
        </div>
    </div>
  )
}

export default Welcome