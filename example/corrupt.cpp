#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "../src/pnm/pnm.hpp"

void check( std::string const& filename )
 {

  std::ifstream ifs( filename.c_str() );
  std::vector<std::uint8_t > data;
  PNM::Info info;

  ifs >> PNM::load( data, info );

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
    std::cout << "Corruption expected." << std::endl;
   }

 }


int main( int argc, char *argv[] )
 {
  std::cout << __FILE__ << std::endl;

  check( "../data/corrupt-comment-eof.pbm" );
  check( "../data/corrupt-corrupt-data.pbm" );
  check( "../data/corrupt-corrupt-size.pbm" );
  check( "../data/corrupt-empty.pbm" );
  check( "../data/corrupt-magic-bad.pbm" );
  check( "../data/corrupt-magic-no.pbm" );

  return EXIT_SUCCESS;
 }

