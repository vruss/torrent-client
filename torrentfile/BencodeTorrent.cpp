//
// Created by Viktor Rosvall on 2020-01-15.
//

#include <iostream>
#include "BencodeTorrent.h"
#include "sha.h"

TorrentFile BencodeTorrent::open(std::istream& stream)
{
    auto data = bencode::decode(stream);
    auto values = boost::get<bencode::dict>(data);

    auto announceString = boost::get<bencode::string>(values.at("announce"));
    auto infoDict = boost::get<bencode::dict>(values.at("info"));

    announce = announceString;
    info = BencodeInfo(infoDict);

    return toTorrentFile(infoDict);
}

TorrentFile BencodeTorrent::toTorrentFile(const bencode::dict& _info)
{
    std::array<uint8_t, 20> hashedInfo = hash(bencode::encode(_info));
    std::vector<std::array<uint8_t, 20>> pieceHashes;
    pieceHashes.push_back(hashedInfo);

    auto torrentFile = TorrentFile(announce,
                                   hashedInfo,
                                   pieceHashes,
                                   info.pieceLength,
                                   info.length,
                                   info.name);
    return torrentFile;
}

std::array<uint8_t, 20> BencodeTorrent::hash(const std::string& bytes)
{
    std::string digest;
    std::array<uint8_t, 20> byteHash{};

    // create hash
    CryptoPP::SHA1 hash;
    hash.Update((const CryptoPP::byte*) bytes.data(), bytes.size());
    digest.resize(hash.DigestSize());
    hash.Final((CryptoPP::byte*) &digest[0]);

    // save hash to byte array
    auto it = digest.data();
    for (int i = 0; i < hash.DigestSize(); i++)
    {
        byteHash.at(i) = (uint8_t) it[i];
    }
    return byteHash;
}


