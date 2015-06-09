/**
   @file
   dot.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/

#ifndef DOT_HPP_INCLUDED_2102087993860788272
#define DOT_HPP_INCLUDED_2102087993860788272


//
// ... ctblas header files
//
#include <ctblas/import.hpp>
#include <ctblas/length.hpp>


namespace ctblas
{
  
  struct Dot
  {

    
    template< 
      typename Xs,
      typename Ys
      >
    constexpr auto
    operator ()( const Xs& xs, const Ys& ys ) const
    {
      
      static_assert( 
	length( xs ) == length( ys ),
	"Dot requires equal vector lengths." );

      return aux( gen_Idx< length( xs ) >(), xs, ys );
      
    }
    
  private:
    
    template< 
    size_t ... indices,
    typename Xs,
    typename Ys
    >
    constexpr auto
    aux( Idx< indices ... >, const Xs& xs, const Ys& ys ) const
    {
      return sum( get< indices >( xs )*get< indices >( ys ) ... );
    }
    
  };  // end of struct dot

  constexpr static auto dot = Dot{};

  
} // end of namespac ctbla


#endif // DOT_HPP_INCLUDED_2102087993860788272
