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


int main( int argc, char *argv[] )
 {

  std::ofstream ofs("image.pbm");
  std::vector<std::uint8_t > data;
  data.resize( 100 * 13 );
  //< In here fill data with something >

  ofs << PNM::save( data, 100, 100, PNM::P1 );

  return EXIT_SUCCESS;
 }

