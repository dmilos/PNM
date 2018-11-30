#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../src/pnm/pnm.hpp"

using namespace std;


#ifdef _MSC_VER
#define DATA_FOLDER "../data"
#define OUT_FOLDER  "../out"
#endif

#ifdef __GNUC__
#define DATA_FOLDER  "./data"
#define OUT_FOLDER   "./out"
#endif


void print( PNM::Info const& info )
 {
  if( true == info.valid() )
   {
    std::cout << "width   = "  << info.width ()    << std::endl;
    std::cout << "height  = "  << info.height()    << std::endl;
    std::cout << "max     = "  << info.max()       << std::endl;
    std::cout << "channel = "  << info.channel()   << std::endl;
    std::cout << "type    = "  << (int)info.type() << std::endl;
   }
  else
   {
    std::cout << "Error type" << std::endl;
   }
 }

int main( int argc, char *argv[] )
 {
   std::vector<std::uint8_t> data;
   PNM::Info info;

   {
    std::ifstream ifs( DATA_FOLDER "/example01.ppm", std::ios::binary );
    ifs >> PNM::load( data, info );
    print( info );
   }

   {
    info.type() = PNM::P3;
    std::ofstream ofs( OUT_FOLDER "/P3-reload" "-txt.ppm", std::ios::binary);
    ofs << PNM::save( data, info );
   }

   {
    info.type() = PNM::P6;
    std::ofstream ofs( OUT_FOLDER "/P3-reload" "-bin.ppm", std::ios::binary );
    ofs << PNM::save( data, info );
   }

  return EXIT_SUCCESS;
 }

