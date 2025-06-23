
import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";
import { BaseQueryApi, FetchArgs } from "@reduxjs/toolkit/query";
import { fetchAuthSession, getCurrentUser } from "aws-amplify/auth";

export interface User {
  userId: string;
  username: string;
  email: string;
  profilePictureUrl?: string;
  cognitoId?: string;
}


const customBaseQuery = async (
    args: string | FetchArgs,
    api: BaseQueryApi,
    extraOptions: {}
) => {
    const baseQuery = fetchBaseQuery({
        baseUrl: process.env.NEXT_PUBLIC_API_BASE_URL,
    });

    try {
        
        const result: any = await baseQuery(args, api, extraOptions);
        
        if (result.data) {
            result.data = result.data.data;
        }
        return result;

    } catch (error) {
        const errorMessage = error instanceof Error ? error.message : "Unknown error";

        return { error: {status: "FETCH_ERROR", error: errorMessage } };
    }
};

export const api = createApi({
    baseQuery: customBaseQuery,
    reducerPath: "api",
    tagTypes: ["Showcases"],
    endpoints: (build) => ({
        getAuthUser: build.query({
            queryFn: async (_, _queryApi, _extraoptions, fetchWithBQ) => {
                try {
                    const user = await getCurrentUser();
                    const session = await fetchAuthSession();
                    if (!session) throw new Error("No session found");
                    const { userSub } = session;
                    const { accessToken } = session.tokens ?? {};
                    
                    // const userDetailsResponse = await fetchWithBQ(`users/${userSub}`);
                    // const userDetails = userDetailsResponse.data as User;

                    // return { data: { user, userSub, userDetails } };
                    return { data: { user, userSub} };
                } catch (error: any) {
                    return { error: error.message || "Could not retrieve user data" };
                }
            },
        }),
        
        getShowcases: build.query<Showcase[], void>({
            query: () => "showcases", 
            providesTags: ["Showcases"],
        }),

        getShowcase: build.query<Showcase, string>({
            query: (id) => `showcases/${id}`,
            providesTags: (result, error, id) => [{ type: "Showcases", id}],
        }),

        createShowcase: build.mutation<Showcase, {artistId: string, artistName: string}>({
            query: (body) => ({
                url: `showcases`,
                method: "POST",
                body,
            }),
            invalidatesTags: ["Showcases"],
        }),

        deleteCourse: build.mutation<{ message: string }, string>({
            query: (id) => ({
                url: `showcases/${id}`,
                method: "DELETE",
            }),
            invalidatesTags: ["Showcases"],
        }),
    }),
});

export const { 
    useGetShowcasesQuery, 
    useGetShowcaseQuery,
    useCreateShowcaseMutation,
    useGetAuthUserQuery,
    useDeleteCourseMutation,
} = api;