/**
   @file
   dot_test.cpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/

//
// ... Standard header files
//
#include <tuple>
#include <array>



//
// ... Third-party header files
//
#include <combine/macro_tools.hpp>

//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/dot.hpp>



int
main( int argc, char** argv )
{
  using ctblas::MakeXn;
  using ctblas::MakeXs;
  using ctblas::dot;

  constexpr auto x = MakeXn< std::array >{}( 1, 2, 3 );
  constexpr auto y = MakeXn< std::array >{}( 4, 5, 6 );
  constexpr auto dotxy = dot( x, y );

  COMBINE_STATIC_ASSERT_EQUAL( dotxy, 32 );
  
  return 0;
}


