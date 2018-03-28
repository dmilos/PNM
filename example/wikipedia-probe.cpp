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


void check( std::string const& filename )
 {
  std::ifstream ifs( filename.c_str() );
  PNM::Info info;

  ifs >> PNM::probe( info );

  print( info );

  std::cout << std::endl;
 }



int main( int argc, char *argv[] )
 {
  std::cout << __FILE__ << std::endl;

  std::cout << "Start: Want error!" << std::endl;
  check( "./data/corrupt-comment-eof.pbm" );
  check( "./data/corrupt-corrupt-data.pbm" );
  check( "./data/corrupt-corrupt-size.pbm" );
  check( "./data/corrupt-empty.pbm" );
  check( "./data/corrupt-magic-bad.pbm" );
  check( "./data/corrupt-magic-no.pbm" );
  std::cout << "End: Want error!" << std::endl;


  std::cout << "Start: Must be OK!" << std::endl;
  check( "./data/wikipedia.pbm" );
  check( "./data/wikipedia.pgm" );
  check( "./data/wikipedia.ppm" );
  check( "./data/wikipedia-onel-line.ppm" );
  std::cout << "End: Must be OK!" << std::endl;

  return EXIT_SUCCESS;
 }

