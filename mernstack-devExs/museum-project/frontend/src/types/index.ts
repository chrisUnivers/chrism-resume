declare global {
    interface Showcase {
        showcaseId: string;
        artId: string;
        description: string;
        artistId: string;
        artistName: string;
        image: string;
        showcaseDateAndTime: string;
        status: "Upcoming" | "Open" | "Closed";
        vibe: string; // sculptures, techno, paintings, live and more!
    }
}

export {};