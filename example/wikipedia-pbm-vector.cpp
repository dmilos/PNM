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

  std::ifstream ifs( DATA_FOLDER "/wikipedia.pbm", std::ios_base::binary );
  std::vector< std::uint8_t > data;
  PNM::Info info;

  ifs >> PNM::load( data, info );

  print( info );

  {
   std::ofstream ofs( OUT_FOLDER "/wikipedia-vector-P4.pbm" );
   ofs << PNM::save( data, info.width(), info.height(), PNM::P4 );
  }

  return EXIT_SUCCESS;
 }

