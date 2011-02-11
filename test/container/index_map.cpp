//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/index_map.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	container_index_map
)
{
	typedef fcppt::container::index_map<
		int
	> int_index_map;

	int_index_map map;

	map[
		2
	] = 42;

	BOOST_REQUIRE(
		map.size() == 3u
	);

	BOOST_REQUIRE(
		map[0] == 0
		&& map[1] == 0
		&& map[2] == 42
	);
}
