/**
   @file
   asum_test.cpp

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
#include <ctblas/asum.hpp>


int
main( int argc, char** argv )
{
  using ctblas::MakeXn;
  using ctblas::asum;

  {
    constexpr auto x = MakeXn< std::array >{}( 1, 2, 3 );
    constexpr auto xasum = asum( x );
    COMBINE_STATIC_ASSERT_EQUAL( xasum, 6 );
  }

  {
    constexpr auto x = MakeXn< std::array >{}( -1, -2, -3 );
    constexpr auto xasum = asum( x );
    COMBINE_STATIC_ASSERT_EQUAL( xasum, 6 );
  }

  
  {
    constexpr auto x = MakeXn< std::array >{}( 1, -2, 3 );
    constexpr auto xasum = asum( x );
    COMBINE_STATIC_ASSERT_EQUAL( xasum, 6 );
  }
  
  
  return 0;
  
}
