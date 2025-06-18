
import React, { useEffect, useState } from 'react'
import { Authenticator } from '@aws-amplify/ui-react';
import { Amplify } from 'aws-amplify';
import "@aws-amplify/ui-react/styles.css"
import { usePathname, useRouter } from 'next/navigation';
import { useGetAuthUserQuery } from '@/state/api';


Amplify.configure({
    Auth: {
        Cognito:{
            userPoolId: process.env.NEXT_PUBLIC_COGNITO_USER_POOL_ID || "",
            userPoolClientId: process.env.NEXT_PUBLIC_COGNITO_USER_POOL_CLIENT_ID || "",
        },
    },
});

const formFields = {
  signUp: {
    username: {
      order: 1,
      placeholder: "Choose a username",
      label: "Username",
      inputprops: { required: true },
    },
    email: {
      order: 1,
      placeholder: "Enter your email address",
      label: "Email",
      inputprops: { type: "email", required: true },
    },
    preferred_username: {
      order: 1,
      placeholder: "Enter your nick name",
      label: "preferred_username",
      inputprops: { type: "preferred_username", required: true },
    },
    password: {
      order: 3,
      placeholder: "Enter your password",
      label: "Password",
      inputprops: { type: "password", required: true },
    },
    confirm_password: {
      order: 4,
      placeholder: "Confirm your password",
      label: "Confirm Password",
      inputprops: { type: "password", required: true },
    },
  },
};
const AuthProvider = ({ children }: any) => {
  const pathString = usePathname();
  const router = useRouter();
  

  const [isSignedIn, setIsSignedIn] = useState(false);
  const isArtistRoute = pathString.startsWith("/artist");

  const { data: currentUser } = useGetAuthUserQuery({});

  useEffect(() => {
    const validateAcc = async () => {
      try {
        if (!currentUser) throw new Error("User not found");
        
        setIsSignedIn(true);
      } catch (error) {
        // console.error("Error auth provider");
        setIsSignedIn(false);
      }
    };

    validateAcc();
  }, []);

  // console.log("Hello");
  // console.log(currentUser?.userDetails);

  if (isArtistRoute && !isSignedIn) {
    return <div className="mt-5">
      <Authenticator formFields={formFields}>{({ user }: any) => 
          user ? (
              <div>{ children }</div>
          ) : (
              <div>
                  <h1>Please sign in below</h1>
              </div>
          )
      }
      </Authenticator>
    </div>
  }

  return (
    <div className="mt-5">
      <div>{ children }</div>
    </div>
  )
  
};

export default AuthProvider