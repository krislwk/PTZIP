cmake_minimum_required(VERSION 3.10)
project(PTZIP)

set(CMAKE_CXX_STANDARD 17)

# Force CROW_USE_BOOST to be ON, and CROW_USE_SYSTEM_ASIO OFF
set(CROW_USE_BOOST ON CACHE BOOL "Use Boost ASIO for Crow")
set(CROW_USE_SYSTEM_ASIO OFF CACHE BOOL "Don't use standalone ASIO")
set(CROW_BUILD_TESTS OFF CACHE BOOL "")
set(CROW_BUILD_EXAMPLES OFF CACHE BOOL "")

# Point to Boost if you're using a local copy
set(BOOST_INCLUDEDIR ${PROJECT_SOURCE_DIR}/boost_1_88_0)

# Add Crow submodule
add_subdirectory(Crow)

# Define your app
add_executable(PTZIP src/main.cpp)

target_include_directories(PTZIP PRIVATE
    ${PROJECT_SOURCE_DIR}/Crow/include
    ${BOOST_INCLUDEDIR}
)

target_link_libraries(PTZIP PRIVATE Crow)

if (WIN32)
    target_link_libraries(PTZIP PRIVATE Crow ws2_32 mswsock)
endif()