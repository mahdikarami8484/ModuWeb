cmake_minimum_required(VERSION 3.10)
project(ModuWeb)

set(CMAKE_CXX_STANDARD 20)

find_package(Drogon REQUIRED)

include_directories(.)

add_executable(ModuWeb main.cpp)

file(GLOB_RECURSE SOURCES
    "controllers/*.cc"
    "plugins/*.cpp"
    "models/*.cpp"
    "filters/*.cpp"
)

target_sources(ModuWeb PRIVATE ${SOURCES})
target_link_libraries(ModuWeb Drogon::Drogon)