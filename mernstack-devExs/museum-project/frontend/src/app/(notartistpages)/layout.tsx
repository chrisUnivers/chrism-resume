import WelcomeHomeNavbar from "@/components/WelcomeHomeNavbar";

export default function HomepageLayout({ children }: {children: React.ReactNode}) {
  return (
    <div className="flex flex-col min-h-screen w-full">
      {/* <WelcomeHomeNavbar /> */}
      <main className="">
        {children}
      </main>
    </div>
  );
}
{/* <HomepageWrapper>{children}</HomepageWrapper> */}
