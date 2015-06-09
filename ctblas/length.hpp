/**
   @file
   length.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <samuel.johnson@halliburton.com>

*/


#ifndef LENGTH_HPP_INCLUDED
#define LENGTH_HPP_INCLUDED


//
// ... ctblas header files
//
#include <ctblas/import.hpp>



namespace ctblas
{

  struct Length
  {
    template< 
      template< typename ... > class T,
      typename ... Xs 
      >
    constexpr auto 
    operator ()( const T< Xs ... >& )
    {
      return count_types< Xs ... >();
    }

    
    template<
      template< typename, size_t > class T,
      typename X,
      size_t n
      >
    constexpr auto
    operator ()( const T< X, n >& )
    {
      return n;
    }
    

    
  };

  constexpr auto static length = Length{};


  
} // end of namespace ctblas


#endif // LENGTH_HPP_INCLUDED
