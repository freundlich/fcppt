//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/interval_distance.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	interval_distance
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				0,
				2
			),
			fcppt::make_homogenous_pair(
				3,
				10
			)
		),
		1
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				3,
				10
			),
			fcppt::make_homogenous_pair(
				0,
				2
			)
		),
		1
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				3,
				5
			),
			fcppt::make_homogenous_pair(
				4,
				6
			)
		),
		0
	);
}