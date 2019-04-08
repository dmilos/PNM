# PNM( Portable Anymap Format ) AKA Netpbm

### Status
  - Done and ready for use.
    - Implemented: P1, P2, P3, P4, P5, P6

### Description
 - PBM, PGM and PPM  reader and writer

### Key features
  - Header~~s~~ only
  - One file to include
  - One file to handle
  - No third parties
  - No additional binaries
  - Out of the box ready
  - No need to recompile or start some install process.
  - API Statistics.
    - Number of namespaces: 1( one )
    - Number of functions: 3 ( three )
    - Number of Classes/Structures: 1 ( one )
    - Number of operators: 2 ( two )

### Load image in to std::vector
```c++
 std::ifstream ifs( "image.pbm", std::ios_base::binary );
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
   // data contain valid information
  }
  // One-liner version. 
  { std::ifstream( "image.pbm", std::ios_base::binary ) >> PNM::load( data, info ); }
```

### Save image from std::vector
```c++
 std::ofstream ofs("image1.pbm");
 std::vector<std::uint8_t > data;

 //< In here fill data with something >

 ofs << PNM::save( data, 100, 100, PNM::P1 );

 // One-liner version
 { std::ofstream("image2.pbm") << PNM::save( data, 100, 100, PNM::P1 ); }
```

### Load data to raw memory by using custom allocator:
```c++
 std::uint8_t *my_allocator( size_t const& size )
  {
   return (std::uint8_t *) malloc( size );
  }

 std::ifstream ifs( "image.pbm", std::ios_base::binary );
 std::uint8_t *data;
 PNM::Info info;

 ifs >> PNM::load( &data, my_allocator, info );
 if( true == info.valid() )
  {
   std::cout << "width   = "  << info.width ()    << std::endl;
   std::cout << "height  = "  << info.height()    << std::endl;
   std::cout << "max     = "  << info.max()       << std::endl;
   std::cout << "channel = "  << info.channel()   << std::endl;
   std::cout << "type    = "  << (int)info.type() << std::endl;
   // data contain valid information allocated by my_allocator
  }

  // One-liner version. 
  { std::ifstream( "image.pbm", std::ios_base::binary ) >> PNM::load( &data, my_allocator, info ); }
```

### Load data from already allocated memory
```c++

 std::ifstream ifs( "image.pbm", std::ios_base::binary );
 std::uint8_t *data = malloc( 100 * 100 * 3 );
 PNM::Info info;

 ifs >> PNM::load( data, info );
 if( true == info.valid() )
  {
   std::cout << "width   = "  << info.width ()    << std::endl;
   std::cout << "height  = "  << info.height()    << std::endl;
   std::cout << "max     = "  << info.max()       << std::endl;
   std::cout << "channel = "  << info.channel()   << std::endl;
   std::cout << "type    = "  << (int)info.type() << std::endl;
   // data contain valid information allocated by my_allocator
  }

  // One-liner version. 
  { std::ifstream( "image.pbm", std::ios_base::binary ) >> PNM::load( data, info ); }
```

### Save data from raw memory
```c++
 std::ofstream ofs( "image1.pgm" );
 std::uint8_t data[ 100 * 100 ];
 //< In here fill data with something >

 ofs << PNM::save( data, 100, 100, PNM::P2 );

 // One-liner version
 { std::ofstream( "image2.pgm" ) << PNM::save( data, 100, 100, PNM::P2 ); }
```

### Probe the file
```c++
 std::ifstream ifs( "image.pbm", std::ios_base::binary );
 PNM::Info info;

 ifs >> PNM::probe( info );
 if( true == info.valid() )
  {
   std::cout << "width   = "  << info.width ()    << std::endl;
   std::cout << "height  = "  << info.height()    << std::endl;
   std::cout << "max     = "  << info.max()       << std::endl;
   std::cout << "channel = "  << info.channel()   << std::endl;
   std::cout << "type    = "  << (int)info.type() << std::endl;
  }

 // One-liner version
 { std::ifstream( "image.pbm" )>> PNM::probe( info ); }
```

### Install
1. Clone this Repository: \
  Examples:
    - Windows : git clone https://github.com/dmilos/PNM.git c:\my-work-folder\my-git-folder\PNM
    - Linux   : git clone https://github.com/dmilos/PNM.git /home/my-user-name/my-work-folder/my-git-folder/PNM
2. Inform compiler where to find headers: \
  Examples:
   - MSVC : /Ic:\my-work-folder\my-git-folder\PNM\src
   - gcc  : -I/home/my-user-name/my-work-folder/my-git-folder/PNM/src

### Links
  - [Wiki page](https://en.wikipedia.org/wiki/Netpbm_format)

### Tested against
- gcc 6.4.0
- MSVC 2015
- MSVC 2017
