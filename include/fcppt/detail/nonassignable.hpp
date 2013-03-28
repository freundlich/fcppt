//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_NONASSIGNABLE_HPP_INCLUDED
#define FCPPT_DETAIL_NONASSIGNABLE_HPP_INCLUDED

#include <fcppt/config.hpp>


#if defined(FCPPT_HAVE_DEFAULTED_AND_DELETED_FUNCTIONS)

#define FCPPT_DETAIL_NONASSIGNABLE(\
	classname\
)\
classname &operator=(classname const &) = delete

#else

#define FCPPT_DETAIL_NONASSIGNABLE(\
	classname\
)\
classname &operator=(classname const &)

#endif

#endif