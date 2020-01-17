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
    std::array<uint8_t, HASH_LENGTH> hashedInfo = hash(bencode::encode(_info));
    std::vector<std::array<uint8_t, HASH_LENGTH>> pieceHashes = splitPieceHashes();

    auto torrentFile = TorrentFile(announce,
                                   hashedInfo,
                                   pieceHashes,
                                   info.pieceLength,
                                   info.length,
                                   info.name);
    return torrentFile;
}

std::array<uint8_t, HASH_LENGTH> BencodeTorrent::hash(const std::string& bytes)
{
    std::string digest;
    std::array<uint8_t, HASH_LENGTH> byteHash{};

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

std::vector<std::array<uint8_t, 20>> BencodeTorrent::splitPieceHashes()
{
    std::vector<std::array<uint8_t, 20>> hashes;

    // check if hash length is correct
    if (info.pieces.length() % HASH_LENGTH != 0)
    {
        std::cerr << "Invalid hash length!\n";
        return hashes;
    }

    // iterate through all hashes
    unsigned int numHashes = info.pieces.length() / HASH_LENGTH;
    for (int i = 0; i < numHashes; i++)
    {
        // substring the hash pieces into separate hash arrays
        std::array<uint8_t, HASH_LENGTH> byteHash{};
        auto hashPtr = info.pieces.substr(i * HASH_LENGTH, HASH_LENGTH).data();
        for (int j = 0; j < HASH_LENGTH; j++)
        {
            byteHash.at(j) = (uint8_t) hashPtr[j];
        }
        hashes.emplace_back(std::array<uint8_t, 20>(byteHash));
    }
    return hashes;
}
