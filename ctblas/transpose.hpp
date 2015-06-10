/**
   @file
   transpose.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>
*/
#ifndef TRANSPOSE_HPP_INCLUDED_107212931473807758
#define TRANSPOSE_HPP_INCLUDED_107212931473807758

namespace ctblas
{

  template< typename A >
  class Transpose
  {

    template< typename B >
    Transpose( const B& b )
      : a( b )
    {}
    
    using value_type = typename A::value_type;
    template< size_t i, size_t j >

    template< size_t i, size_t j >
    constexpr auto
    get() const noexcept
    {
      return get< j, i >( a );
    }
    
  private:
    A const a;
  };

  template< typename A >
  constexpr auto
  transpose( const A& a )

  
} // end of namespace ctblas



#endif // TRANSPOSE_HPP_INCLUDED_107212931473807758
