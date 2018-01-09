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
  std::cout << __FILE__ << std::endl;

  PNM::Info info;
  std::vector<std::uint8_t > data;

  {
   std::ifstream ifs( DATA_FOLDER "/wikipedia.pgm" );
   ifs >> PNM::load( data, info );
  }

  if( false == info.valid() )
   {
    return EXIT_FAILURE;
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-info-instance.pgm";

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
    std::string filename =OUT_FOLDER "/wikipedia-no-info-info.pgm";
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
    std::string filename = OUT_FOLDER "/wikipedia-no-inplace.pgm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, PNM::Info( 24, 7, PNM::P2, 15 ) );
    }

    {
     // reload
     std::ifstream ifs( filename );
     ifs >> PNM::load( data, info );
     print( info );
    }
   }

   {
    std::string filename = OUT_FOLDER "/wikipedia-no-info.pgm";

    {
     std::ofstream ofs( filename );
     ofs << PNM::save( data, 24, 7, PNM::P2, 15 );
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

