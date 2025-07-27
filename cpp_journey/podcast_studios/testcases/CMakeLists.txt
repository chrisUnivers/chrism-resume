cmake_minimum_required(VERSION 3.10.0)

set(This PodStudiosTests)

set(Sources
    podcastroom_test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    PodcastRoomLib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)