/**
   @file
   axpy_test.cpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/


//
// ... Standard header filse
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
#include <ctblas/axpy.hpp>

int
main( int argc, char** argv )
{
  using ctblas::axpy;
  
  // Test the axpy function with a tuple representation of both vectors
  {
    using std::make_tuple;
    using std::get;

    constexpr auto a = 3.0;
    constexpr auto x = make_tuple( 1.0, 2.0, 3.0 );
    constexpr auto y = make_tuple( 4.0, 5.0, 6.0 );
    constexpr auto z = axpy( a, x, y );

    COMBINE_STATIC_ASSERT_EQUAL( get< 0 >( z ), a*get< 0 >( x )+get< 0 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( get< 1 >( z ), a*get< 1 >( x )+get< 1 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( get< 2 >( z ), a*get< 2 >( x )+get< 2 >( y ));

				 
  }
  return 0;
}



