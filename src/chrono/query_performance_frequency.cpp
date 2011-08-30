//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/platform.hpp>
#ifdef FCPPT_WINDOWS_PLATFORM
#include "query_performance_frequency.hpp"
#include <fcppt/config/external_begin.hpp>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <fcppt/config/external_end.hpp>
#include <fcppt/chrono/clock_failure.hpp>
#include <fcppt/text.hpp>

LARGE_INTEGER
fcppt::chrono::query_performance_frequency()
{
	LARGE_INTEGER frequency;

	if(
		::QueryPerformanceFrequency(
			&frequency
		)
		== 0
	)
		throw fcppt::chrono::clock_failure(
			FCPPT_TEXT("QueryPerformanceFrequency() failed!")
		);

	return frequency;
}

#endif
