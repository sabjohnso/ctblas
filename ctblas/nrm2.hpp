/**
   @file
   nrm2.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/
#ifndef NRM2_HPP_INCLUDED_989798946854413741
#define NRM2_HPP_INCLUDED_989798946854413741

//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/dot.hpp>


namespace ctblas
{

  /**  Compute the L-2 norm of vector
   */
  struct Nrm2
  {
    template< typename Xs >
    constexpr auto
    operator ()( const Xs& xs ) const
    {
      return sqrt( dot( xs, xs ));
    }
  }; // end of struct Nrm2

  constexpr static auto nrm2 = Nrm2{};
  
} // end of namespace ctblas


#endif // NRM2_HPP_INCLUDED_989798946854413741
