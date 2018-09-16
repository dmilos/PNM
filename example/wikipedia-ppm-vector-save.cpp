#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "../src/pnm/pnm.hpp"

using namespace std;


#ifdef _MSC_VER
#define DATA_FOLDER  "../data"
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
  std::cout << __FILE__ << std::endl;

  PNM::Info info;
  std::vector<std::uint8_t > data;

  {
   std::ifstream ifs( DATA_FOLDER "/wikipedia.ppm" );
   ifs >> PNM::load( data, info );
  }

  if( false == info.valid() )
   {
    return EXIT_FAILURE;
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-info-instance.ppm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, info );
    }

    {
     // reload
     std::ifstream ifs( filename );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename =OUT_FOLDER "/wikipedia-no-info-info.ppm";
    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, info.width(), info.height(), info.type(), info.max() );
    }

    {
     // reload
     std::ifstream ifs( filename );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-no-inplace.ppm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, PNM::Info( 3, 2, PNM::P3 ) );
    }

    {
     // reload
     std::ifstream ifs( filename );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-no-info.ppm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, 3, 2, PNM::P3 );
    }

    {
     // reload
     std::ifstream ifs( filename );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

  return EXIT_SUCCESS;
 }

