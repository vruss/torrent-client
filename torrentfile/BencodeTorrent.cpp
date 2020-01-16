//
// Created by Viktor Rosvall on 2020-01-15.
//

#include "BencodeTorrent.h"
//#include "../libs/sha1-0.2/sha1.h"
#include "cryptopp/sha.h"
#include "cryptopp/cryptlib.h"
#include <iostream>
#include <hex.h>
#include <files.h>

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
    auto hashedInfo = hash(bencode::encode(_info));
    std::cout << hashedInfo << "\n";
//    return TorrentFile();
}

std::basic_string<char> BencodeTorrent::hash(const std::string& bytes)
{
    using namespace CryptoPP;
    HexEncoder encoder(new FileSink(std::cout));

    std::string msg = "Yoda said, Do or do not. There is no try.";
    std::string digest;

    SHA1 hash;
    hash.Update((const byte*) bytes.data(), bytes.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*) &digest[0]);

    std::cout << "Message: " << msg << std::endl;

    std::cout << "Digest: ";
    StringSource(digest, true, new Redirector(encoder));
    std::cout << std::endl;

//    auto bytes = bencode::encode(boost::get<bencode::dict>(values.at("info")));
//    SHA1* sha1 = new SHA1();
//    sha1->addBytes(bytes, strlen(bytes));
//    unsigned char* digest = sha1->getDigest();
//    sha1->hexPrinter(digest, 20);
//    delete sha1;
//    free(digest);
    return digest;
}


