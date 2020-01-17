//
// Created by Viktor Rosvall on 2020-01-15.
//

#include "TorrentFile.h"

TorrentFile::TorrentFile(const std::string& announce,
                         const std::array<uint8_t, 20>& infoHash,
                         const std::vector<std::array<uint8_t, 20>>& pieceHashes,
                         int pieceLength, int length,
                         const std::string& name)
        : announce(announce),
          infoHash(infoHash),
          pieceHashes(pieceHashes),
          pieceLength(pieceLength),
          length(length),
          name(name)
{
}
