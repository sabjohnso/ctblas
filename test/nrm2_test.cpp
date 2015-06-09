/**
   @file
   nrm2_test.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/

//
// ... Standard header files.
//
#include <array>

//
// ... Third-party header files
//
#include <combine/macro_tools.hpp>

//
// ... ctblas header filse
//
#include <ctblas/import.hpp>
#include <ctblas/nrm2.hpp>

int
main( int argc, char** argv )
{
  
  using ctblas::MakeXn;
  using ctblas::nrm2;

  constexpr auto x = MakeXn< std::array >{}( 3, 4 );
  constexpr auto xnrm2 = nrm2( x );

  COMBINE_STATIC_ASSERT_EQUAL( xnrm2, 5.0 );
  
  return 0;
}
