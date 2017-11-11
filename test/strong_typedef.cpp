//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_input.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <unordered_set>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

FCPPT_MAKE_STRONG_TYPEDEF(
	int &,
	strong_int_ref
);

FCPPT_MAKE_STRONG_TYPEDEF(
	int const &,
	strong_int_const_ref
);

FCPPT_MAKE_STRONG_TYPEDEF(
	unsigned,
	strong_uint
);

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_arithmetic
)
{
FCPPT_PP_POP_WARNING

	strong_int
		test1(
			2
		),
		test2(
			4
		);

	BOOST_CHECK_EQUAL(
		test1 + test2,
		strong_int(6)
	);

	BOOST_CHECK_EQUAL(
		test2 - test1,
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		test1 * test2,
		strong_int(8)
	);

	BOOST_CHECK_EQUAL(
		-test1,
		strong_int(-2)
	);

	BOOST_CHECK_EQUAL(
		test1++,
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		test1,
		strong_int(3)
	);

	BOOST_CHECK_EQUAL(
		test1--,
		strong_int(3)
	);

	BOOST_CHECK_EQUAL(
		test1,
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		++test1,
		strong_int(3)
	);

	BOOST_CHECK_EQUAL(
		--test1,
		strong_int(2)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_assignment_arithmetic
)
{
FCPPT_PP_POP_WARNING

	strong_int test(
		1
	);

	test += strong_int(2);

	BOOST_CHECK_EQUAL(
		test,
		strong_int(3)
	);

	test -= strong_int(1);

	BOOST_CHECK_EQUAL(
		test,
		strong_int(2)
	);

	test *= strong_int(2);

	BOOST_CHECK_EQUAL(
		test,
		strong_int(4)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_assignment_bitwise
)
{
FCPPT_PP_POP_WARNING

	strong_uint test1{
		3u
	};

	test1 &= strong_uint{2u};

	BOOST_CHECK_EQUAL(
		test1,
		strong_uint{2u}
	);

	test1 |= strong_uint{3u};

	BOOST_CHECK_EQUAL(
		test1,
		strong_uint{3u}
	);

	test1 ^= strong_uint{2u};

	BOOST_CHECK_EQUAL(
		test1,
		strong_uint{1u}
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_bitwise
)
{
FCPPT_PP_POP_WARNING

	strong_uint const
		test1(
			2u
		),
		test2(
			3u
		);

	BOOST_CHECK_EQUAL(
		test1
		&
		test2,
		strong_uint{2u}
	);

	BOOST_CHECK_EQUAL(
		test1
		|
		test2,
		strong_uint{3u}
	);

	BOOST_CHECK_EQUAL(
		test1
		^
		test2,
		strong_uint{1u}
	);

	BOOST_CHECK_EQUAL(
		~test1,
		strong_uint{
			~2u
		}
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_comparison
)
{
FCPPT_PP_POP_WARNING

	strong_int const
		test1(
			1
		),
		test2(
			1
		),
		test3(
			2
		);

	BOOST_CHECK(
		test1 == test2
	);

	BOOST_CHECK(
		test1 != test3
	);

	BOOST_CHECK(
		test1 <= test2
	);

	BOOST_CHECK(
		test1 >= test2
	);

	BOOST_CHECK(
		test1 < test3
	);

	BOOST_CHECK(
		test3 > test1
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_io
)
{
FCPPT_PP_POP_WARNING

	{
		std::stringstream stream;

		strong_int const test(
			42
		);

		stream << test;

		strong_int result(
			0
		);

		BOOST_REQUIRE(
			stream >> result
		);

		BOOST_CHECK_EQUAL(
			test,
			result
		);
	}

	{
		std::stringstream stream;

		stream << 42;

		fcppt::optional::object<
			strong_int
		> const result2{
			fcppt::io::extract<
				strong_int
			>(
				stream
			)
		};

		BOOST_CHECK_EQUAL(
			fcppt::optional::make(
				strong_int{
					42
				}
			),
			result2
		);
	}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_hash
)
{
FCPPT_PP_POP_WARNING

	typedef std::unordered_set<
		strong_int
	> hash_set;

	hash_set elements;

	elements.insert(
		strong_int(1)
	);

	elements.insert(
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		elements.count(
			strong_int(1)
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		elements.count(
			strong_int(2)
		),
		1u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	strong_typedef_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_unique_ptr,
		strong_int_ptr
	);

	strong_int_ptr val(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	strong_int_ptr val2(
		std::move(
			val
		)
	);

	BOOST_CHECK_EQUAL(
		*val2.get(),
		42
	);

	strong_int_ptr val3(
		fcppt::make_unique_ptr<
			int
		>(
			10
		)
	);

	val3 =
		std::move(
			val2
		);

	BOOST_CHECK_EQUAL(
		*val3.get(),
		42
	);
}
