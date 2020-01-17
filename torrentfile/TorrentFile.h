//
// Created by Viktor Rosvall on 2020-01-15.
//

#ifndef TORRENT_CLIENT_TORRENTFILE_H
#define TORRENT_CLIENT_TORRENTFILE_H

#define HASH_LENGTH 20

#include <string>
#include <vector>
#include <array>
#include <cstdint>

struct TorrentFile
{
    std::string announce;
    std::array<uint8_t, HASH_LENGTH> infoHash;
    std::vector<std::array<uint8_t, HASH_LENGTH>> pieceHashes;
    int pieceLength;
    int length;
    std::string name;

    TorrentFile(const std::string& announce,
                const std::array<uint8_t, 20>& infoHash,
                const std::vector<std::array<uint8_t, 20>>& pieceHashes,
                int pieceLength,
                int length,
                const std::string& name);


};


#endif //TORRENT_CLIENT_TORRENTFILE_H
