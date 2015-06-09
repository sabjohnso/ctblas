/**
   @file
   scal.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <samuel.johnson@halliburton.com>

*/


#ifndef SCAL_HPP_INCLUDED_365878500907508201
#define SCAL_HPP_INCLUDED_365878500907508201


//
// ... ctblas header files
//
#include <ctblas/import.hpp>


namespace ctblas
{

  template< typename A, typename X >
  constexpr auto
  scal_scalar( const A& a, const X& x )
  {
    return a*x;
  }

  template< size_t index, typename A, template< typename ... > class T, typename ... Xs >
  constexpr auto
  scal_element( const A& a, const T< Xs ... >& xs )
  {
    return scal_scalar( forward< A >( a ), get< index >( xs ));
  }


  struct Scal
  {
    
    template<
      typename A, 
      template< typename ... > class T, 
      typename ...  Xs
      >
    constexpr auto
    operator ()( const A& a, const T< Xs ... >& xs ) const
    {
      return aux( gen_Idx< Xs ... >(), MakeXs<T>(), a,  xs );
    }

    
    template< 
      typename A,
      template< typename, size_t > class T,
      typename X,
      size_t n
      >
    constexpr auto
    operator ()( const A& a, const T< X, n >& xs ) const
    {
      return aux( gen_Idx< n >(), MakeXn<T>(), a, xs );
    }
    

  private:

    template<
    size_t ... indices,
    typename Make,
    typename A, 
    typename Xs
    >
    constexpr auto
    aux( Idx< indices ... >&&, Make&& make, const A& a, const Xs& xs ) const
    {
      return make( scal_scalar( a, get< indices >( xs ) ) ... );
    }

  };

  
  constexpr static auto scal = Scal{};
    
     
  
} // end of namespace ctblas


#endif // ! defined SCAL_HPP_INCLUDED_365878500907508201
