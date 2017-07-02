//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/at_c.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_vector_at_c
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	vector2;

	vector2 const vector_c(
		1,
		2
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::vector::at_c<
			0
		>(
			vector_c
		),
		1
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::vector::at_c<
			1
		>(
			vector_c
		),
		2
	);


	vector2 vector_m(
		1,
		2
	);

	fcppt::math::vector::at_c<
		1
	>(
		vector_m
	) =
		42;

	BOOST_CHECK_EQUAL(
		fcppt::math::vector::at_c<
			1
		>(
			vector_m
		),
		42
	);
}