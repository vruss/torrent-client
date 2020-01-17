cmake_minimum_required(VERSION 3.15)
project(torrent_client)

set(CMAKE_CXX_STANDARD 17)

find_package(Git REQUIRED)

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/libs/cryptopp")
    execute_process(
            COMMAND "${GIT_EXECUTABLE}" clone https://github.com/weidai11/cryptopp.git
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/libs"
    )

    file(
            DOWNLOAD https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/CMakeLists.txt
            ${CMAKE_SOURCE_DIR}/libs/cryptopp/CMakeLists.txt
            SHOW_PROGRESS
    )

    file(
            DOWNLOAD https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/cryptopp-config.cmake
            ${CMAKE_SOURCE_DIR}/libs/cryptopp/cryptopp-config.cmake
            SHOW_PROGRESS
    )
endif()

add_subdirectory(libs/cryptopp)

add_executable(${PROJECT_NAME} main.cpp
        libs/bencode.hpp
        torrentfile/TorrentFile.cpp
        torrentfile/TorrentFile.h
        torrentfile/BencodeTorrent.cpp
        torrentfile/BencodeTorrent.h
        torrentfile/BencodeInfo.cpp
        torrentfile/BencodeInfo.h)

target_link_libraries(${PROJECT_NAME} cryptopp-static)
