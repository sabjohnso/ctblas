/**
   @file
   rotmg.hpp

   @brief
   UNDOCUMENTED

   @author: 
   Samuel Johnson <sabjohnso@yahoo.com>

*/


#ifndef ROTMG_HPP_INCLUDED_1108518522170386403
#define ROTMG_HPP_INCLUDED_1108518522170386403

namespace ctblas
{

  /** Construct the modified Givens transformation matrix, which
      zeros the second component of a 2-vector [sqrt(sd1)*sx1, sqrt(sd2)*sy2 ]^T
  */
  struct RotMG
  {

  };

  constexpr static auto rotmg = RotMG{};
  
} // end of namespace ctblas


#endif // ROTMG_HPP_INCLUDED_1108518522170386403
