project( header-utilities )

if( NOT DEFINED header-utilities_DEPENDENCIES )
    set( header-utilities_DEPENDENCIES TRUE )
endif()

add_library( header-utilities INTERFACE )
target_include_directories( header-utilities INTERFACE src/ )
target_link_libraries( header-utilities INTERFACE catch-adapter INTERFACE Log )
