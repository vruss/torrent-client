//
// Created by Viktor Rosvall on 2020-01-15.
//

#include "BencodeTorrent.h"

TorrentFile BencodeTorrent::open(std::istream& stream)
{


//    return TorrentFile(__cxx11::basic_string(), std::array(), std::vector(), 0, 0, __cxx11::basic_string());
}

BencodeTorrent::BencodeTorrent(std::istream& stream)
{
    auto data = bencode::decode(stream);
    auto values = boost::get<bencode::dict>(data);

    announce = boost::get<bencode::string>(values.at("announce"));
    info = BencodeInfo(boost::get<bencode::dict>(values.at("info")));
}
