#include "../src/pnm/pnm.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;


#ifdef _MSC_VER
#define DATA_FOLDER "../data"
#define OUT_FOLDER  "../out"
#endif

#ifdef __GNUC__
#define DATA_FOLDER  "./data"
#define OUT_FOLDER   "./out"
#endif


void print(PNM::Info const& info)
{
    if (true == info.valid())
    {
        std::cout << "width   = " << info.width() << std::endl;
        std::cout << "height  = " << info.height() << std::endl;
        std::cout << "max     = " << info.max() << std::endl;
        std::cout << "channel = " << info.channel() << std::endl;
        std::cout << "type    = " << (int)info.type() << std::endl;
    }
    else
    {
        std::cout << "Error type" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::vector<std::uint8_t> data;
    PNM::Info info;

    std::string  input;
    std::string output;

    if( 3 != argc )
     {
      std::cout << "Invalid number of parameters" << std::endl;
      return EXIT_FAILURE;
     }

    input  = argv[1];
    output = argv[2];

    {
     std::ifstream ifs(input, ios::binary);
     ifs >> PNM::load( data, info );
     print(info);
    }

    {
     std::ofstream ofs( output , ios::binary );
     ofs << PNM::save( data, info );
    }

    return EXIT_SUCCESS;
}

