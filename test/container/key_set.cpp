//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/key_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <map>
#include <set>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container key_set"
	"[container_key_set]"
)
{
	using
	int_set
	=
	std::set<
		int
	>;

	using
	int_string_map
	=
	std::map<
		int,
		std::string
	>;

	CHECK(
		fcppt::container::key_set<
			int_set
		>(
			int_string_map{ // NOLINT(fuchsia-default-arguments-calls)
				std::make_pair(
					42,
					std::string(
						"test"
					)
				),
				std::make_pair(
					10,
					std::string(
						"test2"
					)
				)
			}
		)
		==
		int_set{ // NOLINT(fuchsia-default-arguments-calls)
			10,
			42
		}
	);
}
