import WelcomeHomeNavbar from "@/components/WelcomeHomeNavbar";
import Image from "next/image";
import Welcome from "./(notartistpages)/welcome/page";

export default function Home() {
  return (
    <div className="flex flex-col min-h-screen w-full">
      <WelcomeHomeNavbar />
      <main className="">
        <Welcome />
      </main>
    </div>
  );
}
