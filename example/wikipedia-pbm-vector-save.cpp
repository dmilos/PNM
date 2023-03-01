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
    std::cout << "maximum = "  << info.maximum()   << std::endl;
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
  std::cout << __FILE__ << std::endl;

  PNM::Info info;
  std::vector<std::uint8_t > data;

  {
   std::ifstream ifs( DATA_FOLDER "/wikipedia.pbm", std::ios_base::binary );
   ifs >> PNM::load( data, info );
  }

  if( false == info.valid() )
   {
    return EXIT_FAILURE;
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-info-instance.pbm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, info );
    }

    {
     // reload
     std::ifstream ifs( filename, std::ios_base::binary );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename =OUT_FOLDER "/wikipedia-no-info-info.pbm";
    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, info.width(), info.height(), info.type() );
    }

    {
     // reload
     std::ifstream ifs( filename, std::ios_base::binary );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-no-inplace.pbm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, PNM::Info( 6, 10, PNM::P1 ) );
    }

    {
     // reload
     std::ifstream ifs( filename, std::ios_base::binary );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-no-info.pbm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, 6, 10, PNM::P1 );
    }

    {
     // reload
     std::ifstream ifs( filename, std::ios_base::binary );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

  return EXIT_SUCCESS;
 }

