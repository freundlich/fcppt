//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_optional
)
{
FCPPT_PP_POP_WARNING
	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	std::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const result(
		fcppt::algorithm::map_optional<
			int_unique_ptr_vector
		>(
			int_vector{
				1,
				2,
				3
			},
			[](
				int const _value
			)
			{
				typedef
				fcppt::optional<
					int_unique_ptr
				>
				optional_ptr;

				return
					_value
					==
					1
					?
						optional_ptr(
							fcppt::make_unique_ptr<
								int
							>(
								_value
							)
						)
					:
						optional_ptr()
					;
			}
		)
	);

	BOOST_REQUIRE(
		result.size()
		==
		1u
	);

	BOOST_CHECK(
		*result[0]
		==
		1
	);
}