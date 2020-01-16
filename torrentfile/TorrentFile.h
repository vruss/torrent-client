//
// Created by Viktor Rosvall on 2020-01-15.
//

#ifndef TORRENT_CLIENT_TORRENTFILE_H
#define TORRENT_CLIENT_TORRENTFILE_H


#include <string>
#include <vector>
#include <array>

struct TorrentFile
{
    std::string announce;
    std::array<int, 20> infoHash;
    std::vector<std::array<int, 20>> pieceHashes;
    int pieceLength;
    int length;
    std::string name;

    TorrentFile(const std::string& announce,
                const std::array<int, 20>& infoHash,
                const std::vector<std::array<int, 20>>& pieceHashes,
                int pieceLength,
                int length,
                const std::string& name);


};


#endif //TORRENT_CLIENT_TORRENTFILE_H
