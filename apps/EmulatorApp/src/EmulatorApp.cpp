// Copyright 2019 Arunabh Sharma

#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char* argv[])
{
    // Read rom file
    std::ifstream rom_file("/home/arunabh-compute/n64-emulator/data/sb2.z64",
                           std::ios::in | std::ios::binary);
    if (!rom_file)
    {
        std::cout << "Unable to open file"
                  << "\n";
    }
    else
    {
        std::cout << "File opened"
                  << "\n";
    }
    rom_file.seekg(0, std::ios::end);
    std::streamsize size = rom_file.tellg();
    rom_file.seekg(0, std::ios::beg);
    std::cout << "File size = " << size << "\n";

    // load data from file into vector
    std::vector<uint8_t> rom_data;
    rom_data.reserve(size);
    rom_data.insert(rom_data.begin(),
                    std::istream_iterator<uint8_t>(rom_file),
                    std::istream_iterator<uint8_t>());
    std::cout << "First byte = " << std::hex << +(rom_data[0]) << "\n";
    std::cout << "Second byte = " << std::hex << +(rom_data[1]) << "\n";

    return 0;
}
