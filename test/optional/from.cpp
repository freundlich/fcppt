//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_optional.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	from_optional
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	typedef
	fcppt::optional<
		int &
	>
	optional_int_ref;


	BOOST_CHECK(
		fcppt::from_optional(
			optional_int(),
			[]
			{
				return
					42;
			}
		)
		==
		42
	);

	BOOST_CHECK(
		fcppt::from_optional(
			optional_int(
				100
			),
			[]
			{
				return
					42;
			}
		)
		==
		100
	);

	int x{
		42
	};

	int y{
		0
	};

	fcppt::from_optional(
		optional_int_ref{
			x
		},
		[
			&y
		]()
		-> int &
		{
			return
				y;
		}
	) = 100;

	BOOST_CHECK(
		x
		==
		100
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	from_optional_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	optional_int_unique_ptr const ptr(
		fcppt::from_optional(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[]{
				return
					fcppt::make_unique_ptr<
						int
					>(
						10
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*ptr.get_unsafe(),
		42
	);
}