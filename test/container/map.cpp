//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/map.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>

namespace
{

typedef std::map<
	unsigned,
	unsigned
> inner_map;

typedef fcppt::container::map<
	inner_map
> ui_map;

}

template class fcppt::container::map<
	inner_map
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	map_insert
)
{
FCPPT_PP_POP_WARNING

	ui_map map;

	map.insert(
		1,
		2
	);

	map.insert(
		3,
		4
	);

	BOOST_REQUIRE(
		map.size() == 2
	);

	BOOST_REQUIRE(
		map[1] == 2
		&& map[3] == 4
	);
}
