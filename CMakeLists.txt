cmake_minimum_required(VERSION 3.15)
project(torrent_client)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/cryptopp)

#SET(CMAKE_CXX_FLAGS -l:libcryptopp.a)

add_executable(torrent_client main.cpp
        libs/bencode.hpp
        libs/sha1-0.2/sha1.cpp
        torrentfile/TorrentFile.cpp
        torrentfile/TorrentFile.h
        torrentfile/BencodeTorrent.cpp
        torrentfile/BencodeTorrent.h
        torrentfile/BencodeInfo.cpp
        torrentfile/BencodeInfo.h)

target_link_libraries(${PROJECT_NAME} cryptopp-static)
