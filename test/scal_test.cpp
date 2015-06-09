/**
   @file
   scal_test.cpp

   @brief
   Test array scaling

   @author: 
   Samuel Johnson <samuel.johnson@halliburton.com>

*/

//
// ... Standard header files
//
#include <tuple>
#include <array>

//
// ... ctblas header files
//
#include <ctblas/scal.hpp>

//
// ... Third-party header files
//
#include <combine/macro_tools.hpp>


int
main( int argc, char** argv )
{

  using std::get;
  using std::is_same;
  using ctblas:: MakeXs;
  using ctblas::MakeXn;
  using ctblas::scal;

  // Test vector scaling with a tuple representation of the vector
  // as an rvalue;
  {
    using std::make_tuple;
    constexpr auto y = scal( 3, make_tuple( 1, 2.0F, 3.0, 4.0L ));
    COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 0 >( y )), int );
    COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 1 >( y )), float );
    COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 2 >( y )), double );
    COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 3 >( y )), long double );

    COMBINE_STATIC_ASSERT_EQUAL( 3,     get< 0 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 6.0F,  get< 1 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 9.0,   get< 2 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 12.0L, get< 3 >( y ));
    
  }


  // Test vector scaling with an array representation of the vector.
  // as an rvalue
  {
    
    using std::array;
    constexpr auto y = scal( 3, MakeXn< array >{}( 1, 2, 3, 4 ));
    COMBINE_STATIC_ASSERT_EQUAL( 3, get< 0 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 6, get< 1 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 9, get< 2 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 12, get< 3 >( y ));
    
  }


  // Test vector scaling with a tuple representation of the vector as
  // an lvalue
  {
     using std::make_tuple;
     constexpr auto x = make_tuple( 1, 2.0F, 3.0, 4.0L );
     constexpr auto y = scal( 3, x );

     COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 0 >( y )), int );
     COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 1 >( y )), float );
     COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 2 >( y )), double );
     COMBINE_STATIC_ASSERT_SAME_DECAY( decltype( get< 3 >( y )), long double );
     
     COMBINE_STATIC_ASSERT_EQUAL( 3,     get< 0 >( y ));
     COMBINE_STATIC_ASSERT_EQUAL( 6.0F,  get< 1 >( y ));
     COMBINE_STATIC_ASSERT_EQUAL( 9.0,   get< 2 >( y ));
     COMBINE_STATIC_ASSERT_EQUAL( 12.0L, get< 3 >( y ));
    
  }

    

  // Test vector scaling with an array representation of the vector.
  // as an rvalue
  {
    
    using std::array;
    constexpr auto x = MakeXn< array >{}( 1, 2, 3, 4 );
    constexpr auto y = scal( 3, x );
    
    COMBINE_STATIC_ASSERT_EQUAL( 3, get< 0 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 6, get< 1 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 9, get< 2 >( y ));
    COMBINE_STATIC_ASSERT_EQUAL( 12, get< 3 >( y ));
    
  }
  

  

  

  return 0;
};



