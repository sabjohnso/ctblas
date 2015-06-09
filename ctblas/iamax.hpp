/**
   @file
   iamax.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/


#ifndef IAMAX_HPP_INCLUDED_935619730829232632
#define IAMAX_HPP_INCLUDED_935619730829232632

//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/length.hpp>

namespace ctblas
{

  /**
     Return the index of a vector element with the maximal absolute value.
   */
  struct Iamax
  {

    
    template< typename Xs >
    constexpr auto
    operator ()( const Xs& xs ) const
    {
      return Aux< length( xs ), 0 >{}(  xs );
    }

  private:

    
    template< size_t, size_t >
    struct Aux;

    template< size_t n >
    struct Aux< n, n >
    {
      template< typename X, typename Xs >
      constexpr auto
      operator()( size_t imax, X amax, const Xs& ) const
      {
	return imax;
      }
    };

    template< size_t n >
    struct Aux< n, 0 >
    {
      template< typename Xs >
      constexpr auto
      operator()( const Xs& xs ) const
      {
	return Aux< n, 1 >{}( 0, abs( get< 0 >( xs )), xs );
      }
    };

    template< size_t n, size_t i >
    struct Aux
    {
      template< typename X, typename Xs >
      constexpr auto
      operator()( size_t imax, X amax, Xs&& xs ) const
      {
	return ( abs( get< i >( xs )) > amax
		 ? ( Aux< n, i+1 >{}( i, abs( get< i >( xs )), xs ))
		 : ( Aux< n, i+1 >{}( imax, amax, xs )));	
      }
    };
       
  }; // end of struct Iamax

  constexpr auto iamax = Iamax{};

} // end of namespace ctblas

#endif // IAMAX_HPP_INCLUDED_935619730829232632
