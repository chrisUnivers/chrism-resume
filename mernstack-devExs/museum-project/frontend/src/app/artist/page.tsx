
import { useCreateShowcaseMutation, useGetAuthUserQuery, useGetShowcasesQuery } from '@/state/api';
import { useRouter } from 'next/navigation'
import React, { useState } from 'react'

const Showcases = () => {
    const router = useRouter();
    const { data: currentUser } = useGetAuthUserQuery({});
    const {
        data: showcases,
        isLoading,
        isError,
    } = useGetShowcasesQuery({ vibe: "all"});

    const [createShowcase] = useCreateShowcaseMutation();
    const [selectVibe, setSelectVibe] = useState("all");

    const handleCreateShowcase = async () => {
        if (!currentUser) return null;
        const currentUserDetails = currentUser?.userDetails;

        const result = await createShowcase({
            artistId: currentUserDetails?.userId,
            artistName: currentUserDetails.username || "No name provided",
        }).unwrap();
        router.push(`/artist/showcase/${result.showcaseId}`);
    };

    if (isError || !showcases) return <div>Error loading showcases.</div>

  return (
    <div>Showcases</div>
  )
}

export default Showcases