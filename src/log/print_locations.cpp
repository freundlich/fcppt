//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/print_locations.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace
{

void
do_print(
	fcppt::io::ostream &,
	fcppt::log::object const &
);

}

void
fcppt::log::print_locations(
	fcppt::io::ostream &_stream,
	fcppt::log::context &_context,
	fcppt::log::location const &_location
)
{
	_context.apply(
		_location,
		fcppt::log::tree_function(
			std::bind(
				&do_print,
				std::ref(
					_stream
				),
				std::placeholders::_1
			)
		)
	);
}

namespace
{

void
do_print(
	fcppt::io::ostream &_stream,
	fcppt::log::object const &_object
)
{
	_stream
		<< _object.location()->string()
		<< FCPPT_TEXT('\n');
}

}
