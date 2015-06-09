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
  ctblas/import.hpp
  ctblas/scal.hpp
  DESTINATION ${CTBLAS_INSTALL_INCLUDE_DIR} )

if( BUILD_TESTS )
  enable_testing()
  include( simple_test )

  add_simplest_test( length )
  add_simplest_test( scal )
  add_simplest_test( axpy )
  add_simplest_test( dot )
  add_simplest_test( nrm2 )
  add_simplest_test( asum )
  add_simplest_test( iamax )
  add_simplest_test( rotg )

endif()

  



