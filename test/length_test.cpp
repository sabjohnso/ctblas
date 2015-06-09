/**
   @file
   length_test.cpp

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
#include <ctblas/length.hpp>


int
main( int argc, char** argv )
{
  using ctblas::length;

  {
    using std::make_tuple;
    constexpr auto x = make_tuple( 1.0, 2.0, 3.0 );
    COMBINE_STATIC_ASSERT_EQUAL( 3, length( x ));
  }

  {
    using ctblas::MakeXn;
    constexpr auto x = MakeXn< std::array >{}( 1.0, 2.0, 3.0 );
    COMBINE_STATIC_ASSERT_EQUAL( 3, length( x ));
  }
    
    
  
  return 0;
}


