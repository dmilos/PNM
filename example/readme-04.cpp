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


int main( int argc, char *argv[] )
 {
  std::ofstream ofs( OUT_FOLDER "image.pgm");
  std::uint8_t data[ 100*100 ];
  //< Fill data with something >

  ofs << PNM::save( data, 100, 100, PNM::P2 );

  return EXIT_SUCCESS;
 }

