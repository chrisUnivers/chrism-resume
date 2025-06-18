import { ReactNode } from "react";

declare global {
    interface Showcase {
        showcaseId: string;
        showcaseTitle: string;
        artId: string;
        description: string;
        artistId: string;
        artistName: string;
        image: string;
        showcaseDateAndTime: string;
        status: "Upcoming" | "Open" | "Closed";
        vibe: string; // sculptures, techno, paintings, live and more!
    }
    
    interface HeaderProps {
        title: string;
        subtitle: string;
        rightElement?: ReactNode;
    }
    interface ShowcaseCardProps {
        showcase: Showcase;
        isSelected?: boolean;
        onClick?: () => void;
    }
}

export {};