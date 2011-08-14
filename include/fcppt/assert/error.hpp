//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_ERROR_HPP_INCLUDED
#define FCPPT_ASSERT_ERROR_HPP_INCLUDED

#include <fcppt/assert/terminate.hpp>

#define FCPPT_ASSERT_ERROR(\
	condition\
)\
FCPPT_ASSERT_TERMINATE(\
	condition\
)

#endif
