#include <iostream>
#include <fstream>
#include "libs/bencode.hpp"

int main()
{
    std::fstream stream("torrentfile/testdata/debian-10.2.0-amd64-netinst.iso.torrent",
                        std::ios::in);

    if (stream.is_open())
    {
        auto data = bencode::decode(stream);
        auto value = boost::get<std::map<std::string, bencode::data>>(data);

        auto announce = value.at("announce");
        std::string announce_t = boost::get<std::string>(announce);


        std::cout << announce_t << "\n";
        auto d = 3;

    }
    else
    {
        std::cout << "Torrent file couldn't not open\n";
    }

    return 0;
}
