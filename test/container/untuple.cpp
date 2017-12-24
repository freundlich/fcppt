//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/container/untuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_untuple
)
{
	std::tuple<
		int,
		std::string
	> const tuple1{
		42,
		"42"
	};

	fcppt::container::untuple(
		tuple1,
		[](
			int const _val,
			std::string const &_string
		)
		{
			BOOST_CHECK_EQUAL(
				_val,
				42
			);

			BOOST_CHECK_EQUAL(
				_string,
				"42"
			);
		}
	);

	fcppt::container::untuple(
		std::make_tuple(
			fcppt::make_unique_ptr<
				int
			>(
				100
			)
		),
		[](
			fcppt::unique_ptr<
				int
			> &&_ptr
		)
		{
			BOOST_CHECK_EQUAL(
				*_ptr,
				100
			);
		}
	);
}
