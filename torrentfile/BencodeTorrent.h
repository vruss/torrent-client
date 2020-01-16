//
// Created by julia on 2020-01-15.
//

#ifndef TORRENT_CLIENT_BENCODETORRENT_H
#define TORRENT_CLIENT_BENCODETORRENT_H

#include "BencodeInfo.h"
#include "TorrentFile.h"

struct BencodeTorrent
{
    string announce;        // the URL of the tracker
    BencodeInfo info;       // maps to a dictionary

    TorrentFile open(const std::string& path);
};


#endif //TORRENT_CLIENT_BENCODETORRENT_H
