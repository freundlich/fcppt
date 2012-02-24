//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_ENABLED_LEVELS_HPP_INCLUDED
#define FCPPT_LOG_ENABLED_LEVELS_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Creates an array with enabled levels including and above a levle

Creates an \link fcppt::log::enabled_level_array \endlink which has every entry
set to true that is greater or equal to \a level.
*/
FCPPT_SYMBOL
fcppt::log::enabled_level_array const
enabled_levels(
	fcppt::log::level::type level
);

}
}

#endif
