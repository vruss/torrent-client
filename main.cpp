#include <iostream>
#include <fstream>
#include "libs/bencode.hpp"
#include "torrentfile/BencodeTorrent.h"

int main()
{
    std::fstream stream("torrentfile/testdata/debian-10.2.0-amd64-netinst.iso.torrent",
                        std::ios::in);

    if (stream.is_open())
    {
        BencodeTorrent bencodeTorrent;
        TorrentFile torrentFile = bencodeTorrent.open(stream);
    }
    else
    {
        std::cout << "Torrent file couldn't not toTorrentFile\n";
    }

    return 0;
}
