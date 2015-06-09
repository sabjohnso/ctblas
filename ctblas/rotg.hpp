/**
   @file
   rotg.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/
#ifndef ROTG_HPP_INCLUDED_332580693265880708
#define ROTG_HPP_INCLUDED_332580693265880708


//
// ... ctblas header files
//
#include <ctblas/import.hpp>


namespace ctblas
{


  
  struct Rotg
  {
      
    template< typename X >
    constexpr auto
    operator()( const X& a, const X& b )
    {
      return abs( a ) > abs( b )
	? aux0( a, b, a, abs( a )+abs( b ))
	: aux0( a, b, b, abs( a )+abs( b ));
    }

  private:
    template< typename X >
    constexpr auto
    aux0( const X& a, const X& b, const X& roe, const X& scale )
    {
      return scale == 0
	? make_tuple( X( 0 ), X( 0 ),  X( 1 ), X( 0 ))
	: aux1( a, b, roe, scale, copysign( 1, scale*hypot( a/scale, b/scale )));
    }

    template< typename X >
    constexpr auto
    aux1( const X& a, const X& b, const X& roe, const X& scale, const X& r )
    {
      return aux2( a, b, r, X( 1 ), a/r, b/r );
    }

    template< typename X >
    constexpr auto
    aux2( const X& a, const X& b, const X& r, const X& z, const X& c, const X& s )
    {
      return abs( a ) > abs( b )
	? make_tuple( r, s, c, s )
	: ( abs( b ) > abs( a ) && c != 0 
	    ? make_tuple( r, 1/c, c, s )
	    : make_tuple( r, z, c, s ));
    }
    
    
  }; // end of struct Rotg

  constexpr static auto rotg = Rotg{};
  
  
} // end of namespace ctblas


#endif // ROTG_HPP_INCLUDED_332580693265880708
