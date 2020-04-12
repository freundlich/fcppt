//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/monad.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/monad/bind.hpp>
#include <fcppt/monad/inner_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

static_assert(
	std::is_same_v<
		fcppt::monad::inner_type<
			fcppt::either::object<
				bool,
				int
			>
		>,
		int
	>
);

}

TEST_CASE(
	"either monad",
	"[either]"
)
{
	using
	either_int
	=
	fcppt::either::object<
		std::string,
		int
	>;

	using
	either_bool
	=
	fcppt::either::object<
		std::string,
		bool
	>;

	auto const bind_function(
		[](
			int const _value
		)
		{
			return
				either_bool(
					_value
					>
					10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				);
		}
	);

	CHECK(
		fcppt::monad::bind(
			either_int(
				std::string(
					"test"
				)
			),
			bind_function
		)
		==
		either_bool{
			std::string{
				"test"
			}
		}
	);

	CHECK(
		fcppt::monad::bind(
			either_int(
				20
			),
			bind_function
		)
		==
		either_bool(
			true
		)
	);

	CHECK(
		fcppt::monad::bind(
			either_int(
				20
			),
			[](
				int
			)
			{
				return
					either_bool(
						std::string(
							"failure"
						)
					);
			}
		)
		==
		either_bool(
			std::string(
				"failure"
			)
		)
	);
}
