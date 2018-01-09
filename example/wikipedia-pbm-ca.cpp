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

std::uint8_t *my_allocator( size_t const& size )
 {
  return (std::uint8_t *)malloc( size );
 }

int main( int argc, char *argv[] )
 {
  std::cout << __FILE__ << std::endl;

  std::ifstream ifs( DATA_FOLDER "/wikipedia.pbm" );
  std::uint8_t *data;
  PNM::Info info;

  ifs >> PNM::load( &data, my_allocator, info );

  print( info );

  {
   std::ofstream ofs( OUT_FOLDER "/wikipedia-ca-P4.pbm", ios_base::binary );
   ofs << PNM::save( data, info.width(), info.height(), PNM::P4 );
  }

  return EXIT_SUCCESS;
 }

