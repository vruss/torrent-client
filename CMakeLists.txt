cmake_minimum_required(VERSION 3.15)
project(torrent_client)

set(CMAKE_CXX_STANDARD 17)

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
