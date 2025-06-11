import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";
import { BaseQueryApi, FetchArgs } from "@reduxjs/toolkit/query";

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
        getShowcases: build.query<Showcase[], { vibe?: string }>({
            query: ({ vibe }) => ({
                url: "showcases",
                params: { vibe }
            }),
            providesTags: ["Showcases"],
        }),
        getShowcase: build.query<Showcase, string>({
            query: (id) => `showcases/${id}`,
            providesTags: (result, error, id) => [{ type: "Showcases", id}],
        })
    }),
});

export const { useGetShowcasesQuery, useGetShowcaseQuery } = api;