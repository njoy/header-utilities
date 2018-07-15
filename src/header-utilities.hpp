#ifndef NJOY_HEADER_UTILITIES
#define NJOY_HEADER_UTILITIES

#include <fstream>
#include <iterator>
#include <memory>
#include <type_traits>

#include "Log.hpp"

namespace njoy{
namespace utility{

/**
 * @brief
 * A alias template used for as a template type parameter to enable SFINAE
 *
 * @details
 * The void_t template is useful for implementing the so-called detection
 * idiom to provide rudimentary compile-time reflection in C++. See the
 * is_iterator template later in this library for a simple executable example,
 * of the use of this template in pratice.
 */
template< class... >
using void_t = void;

/**
 * @brief A generic function to call to a parameter types copy ctor
 *
 * @details
 * This function is convenient in conjunction with the idiom of always accepting
 * sink arguments by r-value reference (used throughout NJOY21 libraries). When
 * passing an l-value to such a function, the user can opt to either explicitly
 * move (using std::move) or explicitly copy (using utility::copy) the l-value.
 */
template< typename T >
T copy( const T& t ){ return t; }

/** @brief An alias to a parameter type's nested element_type alias */
template< typename T >
using element_type = typename std::decay_t<T>::element_type;

/**
 * @brief
 * An alias to a parameter type's nested iterator_category alias
 * (with special treament for pointers)
 */
template< typename T >
using iterator_category =
  typename std::iterator_traits< std::decay_t<T> >::iterator_category;

/** @brief An alias to a parameter type's nested iterator alias */
template< typename T >
using iterator = typename std::decay_t<T>::iterator;

#include "header-utilities/is_shared_ptr.hpp"
#include "header-utilities/is_unique_ptr.hpp"
#include "header-utilities/is_iterator.hpp"
#include "header-utilities/is_container.hpp"
#include "header-utilities/is_range.hpp"
#include "header-utilities/Require.hpp"
#include "header-utilities/exponentialSearch.hpp"
#include "header-utilities/src/dereference.hpp"
#include "header-utilities/src/echoErroneousLine.hpp"
#include "header-utilities/src/slurpFileToMemory.hpp"

}
}

#endif
