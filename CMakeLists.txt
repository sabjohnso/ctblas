cmake_minimum_required( VERSION 2.8.4 )

project( CTBLAS )


set( CMAKE_CXX_FLAGS  "-std=c++1y")



# !!!! FIXME: This should use a FindPackage command
set( COMBINE_INCLUDE_DIR "/usr/local/include" )

option( BUILD_TESTS "Build the tests?" ON )

set( CMAKE_MODULE_PATH
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  "${COMBINE_INCLUDE_DIR}/combine/cmake"
  ${CMAKE_MODULE_PATH} )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${COMBINE_INCLUDE_DIR} )

include( ctblasVersion )
set( CTBLAS_VERSION
  "${CTBLAS_MAJOR_VERSION}.${CTBLAS_MINOR_VERSION}.${CTBLAS_BUILD_VERSION}" )

if( NOT CTBLAS_INSTALL_INCLUDE_DIR )
  set( CTBLAS_INSTALL_INCLUDE_DIR include/ctblas-${CTBLAS_MAJOR_VERSION}.${CTBLAS_MINOR_VERSION}/ctblas )
endif()



install( FILES
  ctblas/asum.hpp
  ctblas/axpy.hpp
  ctblas/dot.hpp
  ctblas/iamax.hpp
  ctblas/import.hpp
  ctblas/length.hpp
  ctblas/nrm2.hpp
  ctblas/rotg.hpp
  ctblas/rotmg.hpp
  ctblas/scal.hpp
  DESTINATION ${CTBLAS_INSTALL_INCLUDE_DIR} )

if( BUILD_TESTS )
  
  enable_testing()
  include( simple_test )

  # Tests for Level 1 routines
  add_simplest_test( length )
  add_simplest_test( scal )
  add_simplest_test( axpy )
  add_simplest_test( dot )
  add_simplest_test( nrm2 )
  add_simplest_test( asum )
  add_simplest_test( iamax )
  add_simplest_test( rotg )
  add_simplest_test( rotmg )
  add_simplest_test( rot )
  add_simplest_test( rotm )

  #
  # ... Tests for Level 2 routines
  #
  add_simplest_test( gemv )
  add_simplest_test( gbmv )
  add_simplest_test( symv )
  add_simplest_test( sbmv )
  add_simplest_test( spmv )
  add_simplest_test( trmv )
  add_simplest_test( tbmv )
  add_simplest_test( tpmv )
  add_simplest_test( trsv )
  add_simplest_test( tbsv )
  add_simplest_test( tpsv )
  add_simplest_test( ger  )
  add_simplest_test( syr  )
  add_simplest_test( spr  )
  add_simplest_test( syr2 )
  add_simplest_test( spr2 )
  
  
  
  #
  # ... Tests for Level 3 routines
  #
  add_simplest_test( gemm )
  add_simplest_test( symm )
  add_simplest_test( syrk )
  add_simplest_test( syr2k )
  add_simplest_test( trmm )
  add_simplest_test( trsm )

endif()
