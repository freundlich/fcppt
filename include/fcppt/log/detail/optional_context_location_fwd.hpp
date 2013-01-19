//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_OPTIONAL_CONTEXT_LOCATION_FWD_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_OPTIONAL_CONTEXT_LOCATION_FWD_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/log/context_location_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

typedef fcppt::optional<
	fcppt::log::context_location
> optional_context_location;

}
}
}

#endif
