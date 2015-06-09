/**
   @file
   axpy.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/


#ifndef AXPY_HPP_INCLUDED_77552348985638025
#define AXPY_HPP_INCLUDED_77552348985638025

//
// ... ctblas header files
//
#include <ctblas/import.hpp> // -> MakeXs, MakeXn, gen_Idx
#include <ctblas/scal.hpp>  // -> scal

namespace ctblas
{


  struct Axpy
  {

        
    template<
      typename A,
      typename Xs,
      template< typename ... > class T, 
      typename ...  Ys
      >
    constexpr auto
    operator ()( const A& a, Xs const& xs, const T< Ys ... >& ys ) const
    {
      return aux( gen_Idx< Ys ... >(), MakeXs<T>(), scal( a, xs ),  ys );
    }

    
    template< 
      typename A,
      typename Xs,
      template< typename, size_t > class T,
      typename Y,
      size_t n
      >
    constexpr auto
    operator ()( const A& a, Xs const& xs, const T< Y, n >& ys ) const
    {
      return aux( gen_Idx< n >(), MakeXn<T>(), scal( a, xs ), ys );
    }

  private:
    
    template<
    size_t ... indices,
    typename Make,
    typename AXs,
    typename Ys
    >
    constexpr auto
    aux( Idx< indices ... >&&, Make&& make, const AXs& axs, const Ys& ys ) const
    {
      return make( get<indices>( axs )+get<indices>( ys ) ... );
    }

    
  };

  constexpr static auto axpy = Axpy{};


  
  
} // end of namespace ctblas


#endif // ! defined AXPY_HPP_INCLUDED_77552348985638025
