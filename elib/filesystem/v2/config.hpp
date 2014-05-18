#ifndef ELIB_FILESYSTEM_V2_CONFIG_HPP
#define ELIB_FILESYSTEM_V2_CONFIG_HPP
# 
# include <elib/config.hpp>
# 
# if !defined(ELIB_CONFIG_POSIX)
#   error "elib filesystem requires a POSIX enviroment "
          "please use the CMake option CONFIG_LIB_FILESYSTEM to disable this library"
# endif
# 
#endif /* ELIB_FILESYSTEM_V2_CONFIG_HPP */