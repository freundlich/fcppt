/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_CHRONO_SYSTEM_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_SYSTEM_CLOCK_HPP_INCLUDED

#include <fcppt/chrono/system_clock_fwd.hpp>
#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/time_point_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/ratio.hpp>
#include <fcppt/symbol.hpp>
#include <ctime>

namespace fcppt
{
namespace chrono
{

/// Provides the system clock.
/** This clock can be used to display the current time.
 * It is not suitable for measuring time differences as the system clock
 * can change anytime without you noticing. For example the user changes
 * the systme clock or a date client updates it.
*/
class system_clock
{
public:
	typedef chrono::rep rep;

	typedef fcppt::micro period;

	typedef chrono::duration<
		rep,
		period
	> duration;

	typedef chrono::time_point<
		system_clock
	> time_point;

	static bool const is_monotonic = false;

	FCPPT_SYMBOL static
	time_point
	now();

	FCPPT_SYMBOL static
	std::time_t
	to_time_t(
		time_point const &
	);

	FCPPT_SYMBOL
	static time_point
	from_time_t(
		std::time_t
	);
};

}
}

#endif
