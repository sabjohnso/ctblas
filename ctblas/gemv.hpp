/**
   @file
   gemv.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/


#ifndef GEMV_HPP_INCLUDED_2112298692129861656
#define GEMV_HPP_INCLUDED_2112298692129861656

//
// ... ctblas header files
//
#include <ctblas/flags.hpp>

namespace ctblas
{

  
  struct GeMV
  {
    constexpr auto
    operator()( trans trans, const A& alpha, const Matrix& a, const X& x, const B& beta, const Y& y )
    {
      return 0;
    }
  private:
    template< typename
    aux
    
  }; // end of struct GeMV

  constexpr static auto gemv = GeMV{};

  

  
} // end of namespace ctblas


#endif // ! defined GEMV_HPP_INCLUDED_2112298692129861656
