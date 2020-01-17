//
// Created by Viktor Rosvall on 2020-01-15.
//

#ifndef TORRENT_CLIENT_BENCODETORRENT_H
#define TORRENT_CLIENT_BENCODETORRENT_H

#include <cstdint>
#include "BencodeInfo.h"
#include "TorrentFile.h"

class BencodeTorrent
{
private:
    bencode::string announce;       // the URL of the tracker
    BencodeInfo info;               // maps to a dictionary

    TorrentFile toTorrentFile(const bencode::dict& info);

    static std::array<uint8_t, HASH_LENGTH> hash(const std::string& bytes);

    std::vector<std::array<uint8_t, HASH_LENGTH>> splitPieceHashes();

public:
    TorrentFile open(std::istream& stream);

};


#endif //TORRENT_CLIENT_BENCODETORRENT_H
