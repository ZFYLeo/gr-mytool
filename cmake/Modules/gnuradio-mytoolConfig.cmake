find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_MYTOOL gnuradio-mytool)

FIND_PATH(
    GR_MYTOOL_INCLUDE_DIRS
    NAMES gnuradio/mytool/api.h
    HINTS $ENV{MYTOOL_DIR}/include
        ${PC_MYTOOL_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_MYTOOL_LIBRARIES
    NAMES gnuradio-mytool
    HINTS $ENV{MYTOOL_DIR}/lib
        ${PC_MYTOOL_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-mytoolTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_MYTOOL DEFAULT_MSG GR_MYTOOL_LIBRARIES GR_MYTOOL_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_MYTOOL_LIBRARIES GR_MYTOOL_INCLUDE_DIRS)
