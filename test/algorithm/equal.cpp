//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/equal.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <list>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_equal
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::algorithm::equal(
			std::vector<
				int
			>{
				1,
				2
			},
			std::list<
				int
			>{
				1,
				2
			}
		)
	);

	BOOST_CHECK(
		!fcppt::algorithm::equal(
			std::vector<
				int
			>{
				1
			},
			std::list<
				int
			>{
				1,
				2
			}
		)
	);

	BOOST_CHECK(
		!fcppt::algorithm::equal(
			std::vector<
				int
			>{
				1,
				3
			},
			std::list<
				int
			>{
				1,
				2
			}
		)
	);
}