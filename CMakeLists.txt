########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.14 )
project( header-utilities LANGUAGES CXX )

########################################################################
# Dependencies
########################################################################

include( cmake/header-utilities_dependencies.cmake )

########################################################################
# Project targets
########################################################################

add_library( header-utilities INTERFACE )
target_include_directories( header-utilities INTERFACE src/ )
target_link_libraries( header-utilities
    INTERFACE catch-adapter
    INTERFACE Log
    )
