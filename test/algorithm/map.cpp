//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

typedef
std::vector<
	int
>
int_vector;

typedef
std::vector<
	int_unique_ptr
>
int_unique_ptr_vector;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map
)
{
FCPPT_PP_POP_WARNING

	int_unique_ptr_vector const ptrs{
		fcppt::assign::make_container<
			int_unique_ptr_vector
		>(
			fcppt::make_unique_ptr<
				int
			>(
				1
			),
			fcppt::make_unique_ptr<
				int
			>(
				2
			)
		)
	};

	int_vector const result(
		fcppt::algorithm::map<
			int_vector
		>(
			ptrs,
			[](
				int_unique_ptr const &_value
			)
			{
				return
					*_value;
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		ptrs.size()
	);

	BOOST_CHECK_EQUAL(
		result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		result[1],
		2
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_move
)
{
FCPPT_PP_POP_WARNING

	int_vector const ints{
		1,
		2
	};

	int_unique_ptr_vector const result(
		fcppt::algorithm::map<
			int_unique_ptr_vector
		>(
			ints,
			[](
				int const _value
			)
			{
				return
					fcppt::make_unique_ptr<
						int
					>(
						_value
					);
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		result.size(),
		ints.size()
	);

	BOOST_CHECK_EQUAL(
		*result[0],
		1
	);

	BOOST_CHECK_EQUAL(
		*result[1],
		2
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_mpl
)
{
FCPPT_PP_POP_WARNING

	typedef
	boost::mpl::vector2<
		boost::mpl::int_<
			1
		>,
		boost::mpl::int_<
			2
		>
	>
	types;

	int_vector const ints(
		fcppt::algorithm::map<
			int_vector
		>(
			types{},
			[](
				auto const _value
			)
			{
				FCPPT_USE(
					_value
				);

				typedef
				fcppt::tag_type<
					decltype(
						_value
					)
				>
				type;

				return
					type::value;
			}
		)
	);

	BOOST_REQUIRE_EQUAL(
		ints.size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		ints[0],
		1
	);

	BOOST_CHECK_EQUAL(
		ints[1],
		2
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_array
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::array<
		int,
		2
	>
	source_array;

	typedef
	std::array<
		std::string,
		2
	>
	dest_array;

	dest_array const result(
		fcppt::algorithm::map<
			dest_array
		>(
			source_array{{
				1,
				2
			}},
			[](
				int const _value
			)
			-> std::string
			{
				return
					fcppt::insert_to_std_string(
						_value
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		),
		"1"
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		),
		"2"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_array_move
)
{
FCPPT_PP_POP_WARNING

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_unique_ptr,
		strong_ptr
	);

	typedef
	std::array<
		int_unique_ptr,
		2
	>
	source_array;

	typedef
	std::array<
		strong_ptr,
		2
	>
	dest_array;

	dest_array const result(
		fcppt::algorithm::map<
			dest_array
		>(
			source_array{{
				fcppt::make_unique_ptr<
					int
				>(
					1
				),
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			}},
			[](
				int_unique_ptr &&_value
			)
			-> strong_ptr
			{
				return
					strong_ptr{
						std::move(
							_value
						)
					};
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).get(),
		1
	);

	BOOST_CHECK_EQUAL(
		*std::get<
			1
		>(
			result
		).get(),
		2
	);
}
