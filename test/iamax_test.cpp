/**
   @file
   iamax_test.cpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/

//
// ... Standard header files
//
#include <array>

//
// ... Third-party header files
//
#include <combine/macro_tools.hpp>


//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/iamax.hpp>


int
main( int argc, char** argv )
{
  using ctblas::MakeXn;
  using ctblas::iamax;

  {
    constexpr auto x = MakeXn<std::array>{}( 1, 2, 3, 4 );
    constexpr auto imx = iamax( x );
    COMBINE_STATIC_ASSERT_EQUAL( imx, 3 );
  }

  
  {
    constexpr auto x = MakeXn<std::array>{}( 4, 1, 2, 3 );
    constexpr auto imx = iamax( x );
    COMBINE_STATIC_ASSERT_EQUAL( imx, 0 );
  }

  
  {
    constexpr auto x = MakeXn<std::array>{}( 1, 4, 2, 3 );
    constexpr auto imx = iamax( x );
    COMBINE_STATIC_ASSERT_EQUAL( imx, 1 );
  }
  
  return 0;
}



