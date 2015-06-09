/**
   @file
   asum.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/


#ifndef ASUM_HPP_INCLUDED_1524905224300727796
#define ASUM_HPP_INCLUDED_1524905224300727796



//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/length.hpp>


namespace ctblas
{

  /** Compute the L-1 norm of a vector.
   */
  struct Asum
  {
    
    template< typename Xs >
    constexpr auto
    operator ()( const Xs& xs ) const
    {
      return aux( gen_Idx< length( xs ) >(), xs );
    }

  private:

    template<
      size_t ... indices,
    typename Xs
    >
    constexpr auto
    aux( Idx< indices ... >, const Xs& xs ) const
    {
      return sum( abs( get< indices >( xs )) ... );
    }
    
  }; // end of struct asum
    
  constexpr auto asum = Asum{};
  

  
}// end of namespace ctblas


#endif // ASUM_HPP_INCLUDED_1524905224300727796
