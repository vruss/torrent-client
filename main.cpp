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
        BencodeTorrent bencodeTorrent(stream);
        std::cout << "Opened: " << bencodeTorrent.info.name
                  << " with tracker URL: " << bencodeTorrent.announce << "\n";

//        auto torrentFile = bencodeTorrent.open(stream);
    }
    else
    {
        std::cout << "Torrent file couldn't not open\n";
    }

    return 0;
}
