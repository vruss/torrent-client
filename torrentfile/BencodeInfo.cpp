//
// Created by Viktor Rosvall on 2020-01-16.
//

#include "BencodeInfo.h"

BencodeInfo::BencodeInfo(const bencode::dict& info)
{
    pieces = boost::get<bencode::string>(info.at("pieces"));
    pieceLength = boost::get<bencode::integer>(info.at("piece length"));
    length = boost::get<bencode::integer>(info.at("length"));
    name = boost::get<bencode::string>(info.at("name"));

    bencodeString = bencode::encode(info);
}

