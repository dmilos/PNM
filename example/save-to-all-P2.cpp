#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "../src/pnm/pnm.hpp"

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
    std::ifstream ifs( DATA_FOLDER "/example01.pgm", ios::binary );
    ifs >> PNM::load( data, info );
    print( info );
   }

   {
    info.type() = PNM::P2;
    std::ofstream ofs( OUT_FOLDER "/P2-reload" "-txt.pgm", ios::binary);
    ofs << PNM::save( data, info );
   }

   {
    info.type() = PNM::P5;
    std::ofstream ofs( OUT_FOLDER "/P2-reload" "-bin.pgm", ios::binary );
    ofs << PNM::save( data, info );
   }

  return EXIT_SUCCESS;
 }

