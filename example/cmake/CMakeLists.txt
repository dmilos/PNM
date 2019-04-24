cmake_minimum_required(VERSION 2.8)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

message( WARNING "Not reliable. Use make.sh or MSVC files" )

#primary variables
set( name_bare       "PNM" )
project( ${name_bare} )

set( directory__root "${CMAKE_SOURCE_DIR}/../.." )

set( directory_source          "${directory__root}/src" )
set( directory_include         "${directory__root}/src" )
set( directory_example         "${directory__root}/example" )
set( directory_temp            "${directory__root}/temp" )

set( project_version "1.0.0.0" )#!< TODO Take this from INI
set( name_full ${name_bare}Exe-${project_version} )


#secondary variables
set( directory_output  ${name_bare}-${CMAKE_CXX_COMPILER}-${CMAKE_CXX_COMPILER_VERSION} )

set( directory_obj    "${directory_temp}/${directory_output}/obj" )
set( directory_lib    "${directory_temp}/${directory_output}/lib" )
set( directory_pdb    "${directory_temp}/${directory_output}/pdb" )
set( directory_dll    "${directory_temp}/${directory_output}/dll" )

set( hpp_file_list    "./hpp.lst.txt" )
set( cpp_file_list    "./cpp.lst.txt" )

#Processing

file( GLOB_RECURSE SOURCE_HPP "${directory_source}/src/*.hpp")

#file( STRINGS ${hpp_file_list} FILE_LIST )
#message("${FILE_LIST}")
#foreach(file_item IN LISTS FILE_LIST )
#  message("${file_item}")
#  list( APPEND hpp_files "${directory_source}/${file_item}")
#endforeach(file_item)


file( STRINGS ${cpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_CPP "${directory_example}/${file_item}")
endforeach(file_item)
if( MSVC )
  source_group( TREE "${directory_source}"  FILES ${SOURCE_HPP} )
  source_group( TREE "${directory_example}" FILES ${SOURCE_CPP} )
endif()
include_directories( "${directory_include}")

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4624")
endif()

add_executable(${name_full} ${SOURCE_CPP} ${SOURCE_HPP})

