/**
   @file
   rotg_test.cpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/

//
// ... Standard header files
//
#include <limits>
#include <iostream>
#include <tuple>


//
// ... Third-party header files
//
#include <combine/macro_tools.hpp>

//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/rotg.hpp>



using std::get;

using ctblas::MakeXn;
using ctblas::rotg;
using Index = ctblas::RotG::Index;

constexpr auto a   = MakeXn< std::array >{}( 0.3,  0.4, -0.3, -0.4, -0.3,  0.0,  0.0,  1.0 );
constexpr auto b   = MakeXn< std::array >{}( 0.4,  0.3,  0.4,  0.3, -0.4,  0.0,  1.0,  0.0 );
constexpr auto rex = MakeXn< std::array >{}( 0.5,  0.5,  0.5, -0.5, -0.5, 0.0, 1.0, 1.0 );
constexpr auto zex = MakeXn< std::array >{}( 1.0/0.6, 0.6, -1.0/0.6, -0.6, 1.0/0.6, 0.0, 1.0, 0.0 );


constexpr auto tol = 10.0*std::numeric_limits< double >::epsilon();

template< size_t index_test >
struct Test
{
  Test()
  {
    constexpr auto result = rotg( get< index_test >( a ), get< index_test >( b ));

    COMBINE_STATIC_ASSERT_ROUGHLY_EQUAL( get< index_test >( rex ), get< Index::r >( result ), tol );
    COMBINE_STATIC_ASSERT_ROUGHLY_EQUAL( get< index_test >( zex ), get< Index::z >( result ), tol );
  }
};



int
main( int argc, char** argv )
{

  Test< 0 >();
  Test< 1 >();
  Test< 2 >();
  Test< 3 >();
  Test< 4 >();
  Test< 5 >();
  Test< 6 >();
  Test< 7 >();
  
  return 0;

  
}
