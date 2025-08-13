cmake_minimum_required(VERSION 3.10.0)

set(This PodcastRoomLib)

set(Headers
    StudioRoom.h
    EventSingIn.h
)

set(Sources
    StudioRoom.cpp
    EventSingIn.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})