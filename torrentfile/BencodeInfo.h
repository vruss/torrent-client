//
// Created by julia on 2020-01-16.
//

#ifndef TORRENT_CLIENT_BENCODEINFO_H
#define TORRENT_CLIENT_BENCODEINFO_H

#include <string>
#include "../libs/bencode.hpp"

using integer = long long;
using string = std::string;
using list = std::vector<bencode::data>;
using dict = std::map<std::string, bencode::data>;

struct BencodeInfo
{
    string pieces;          // SHA1 hash of pieces
    integer pieceLength;    // number of bytes in each piece the file is split into
    integer length;         // length of file in bytes
    string name;            // advisory file name
};


#endif //TORRENT_CLIENT_BENCODEINFO_H
