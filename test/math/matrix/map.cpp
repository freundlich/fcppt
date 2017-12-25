//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/map.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	matrix_map
)
{
	typedef
	fcppt::math::matrix::static_<
		unsigned,
		2,
		2
	>
	uimat2;

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>
	imat2;

	BOOST_CHECK_EQUAL(
		fcppt::math::matrix::map(
			uimat2{
				fcppt::math::matrix::row(
					1u,2u
				),
				fcppt::math::matrix::row(
					3u,4u
				)
			},
			[](
				unsigned const _val
			)
			{
				return
					fcppt::cast::to_signed(
						_val
					);
			}
		),
		imat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		)
	);
}