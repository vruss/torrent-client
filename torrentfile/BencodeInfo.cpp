//
// Created by Viktor Rosvall on 2020-01-16.
//

#include "BencodeInfo.h"

BencodeInfo::BencodeInfo(const bencode::dict& dict)
{
    pieces = boost::get<bencode::string>(dict.at("pieces"));
    pieceLength = boost::get<bencode::integer>(dict.at("piece length"));
    length = boost::get<bencode::integer>(dict.at("length"));
    name = boost::get<bencode::string>(dict.at("name"));
}

