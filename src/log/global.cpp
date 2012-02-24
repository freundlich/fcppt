//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/log/global.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/parameters/object.hpp>


namespace
{

fcppt::log::object global_log(
	fcppt::log::parameters::object()
	.level_defaults(
		fcppt::io::clog(),
		fcppt::log::level::debug
	)
	.formatter(
		fcppt::log::format::create_prefix(
			FCPPT_TEXT("fcppt")
		)
	)
	.enabled(
		true
	)
);

}

fcppt::log::object &
fcppt::log::global()
{
	return global_log;
}
