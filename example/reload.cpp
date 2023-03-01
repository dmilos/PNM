#include "../src/pnm/pnm.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#ifdef _MSC_VER
#define DATA_FOLDER "../data"
#define OUT_FOLDER  "../out"
#endif

#ifdef __GNUC__
#define DATA_FOLDER  "./data"
#define OUT_FOLDER   "./out"
#endif


void print(PNM::Info const& info)
 {
  if (true == info.valid())
   {
    std::cout << "width   = " << info.width()     << std::endl;
    std::cout << "height  = " << info.height()    << std::endl;
    std::cout << "maximum = "  << info.maximum()   << std::endl;
    std::cout << "channel = " << info.channel()   << std::endl;
    std::cout << "type    = " << (int)info.type() << std::endl;
   }
  else
   {
    std::cout << "Error type" << std::endl;
   }
 }


std::uint8_t *my_allocator( size_t const& size )
 {
  return (std::uint8_t *) malloc( size );
 }

int main_allocator(int argc, char *argv[])
 {
  std::uint8_t *data;
  PNM::Info info;

  std::string  input;
  std::string output;

  if( 3 != argc )
   {
    std::cout << "Invalid number of parameters" << std::endl;
    return EXIT_FAILURE;
   }

  input  = argv[1];
  output = argv[2];

  {
   std::ifstream( input, std::ios::binary ) >> PNM::load( &data, my_allocator, info );
   print(info);
  }

  {
   std::ofstream( output , std::ios::binary ) << PNM::save( data, info );
  }

  free( data );
  return EXIT_SUCCESS;
 }


int main_vector(int argc, char *argv[])
 {
  std::vector<std::uint8_t> data;
  PNM::Info info;

  std::string  input;
  std::string output;

  if( 3 != argc )
   {
    std::cout << "Invalid number of parameters" << std::endl;
    return EXIT_FAILURE;
   }

  input  = argv[1];
  output = argv[2];

  {
   std::ifstream ifs( input, std::ios::binary );
   ifs >> PNM::load( data, info );
   print(info);
  }

  {
   std::ofstream ( output , std::ios::binary ) << PNM::save( data, info );
  }

  return EXIT_SUCCESS;
 }

int main(int argc, char *argv[])
 {
  char *arg_value[3];
  arg_value[0] = argv[0];
  arg_value[1] = argv[1];
  arg_value[2] = argv[2];

  {
   std::string o = "A"; o += argv[2];
   arg_value[2] = const_cast<char*>( o.c_str() );
   main_allocator( argc, argv );
  }

  {
   std::string o = "V"; o += argv[2];
   arg_value[2] = const_cast<char*>( o.c_str() );
   main_vector( argc, argv );
  }

  return EXIT_SUCCESS;
 }
