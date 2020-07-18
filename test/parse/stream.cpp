//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/parse/parse.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/detail/stream_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ios>
#include <istream>
#include <sstream>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::stream",
	"[parse]"
)
{
	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	std::istringstream string_stream{
		"xy\nz\n"
	};

	fcppt::parse::detail::stream<
		char
	> stream{
		fcppt::reference_to_base<
			std::istream
		>(
			fcppt::make_ref(
				string_stream
			)
		)
	};

	auto const parse_one{
		[
			&stream
		]{
			fcppt::parse::parse(
				fcppt::parse::char_{},
				stream,
				fcppt::parse::epsilon{}
			);
		}
	};

	using
	position
	=
	fcppt::parse::position<
		char
	>;

	using
	offset
	=
	position::pos_type;

	CHECK(
		stream.get_position()
		==
		position{
			offset{},  // NOLINT(fuchsia-default-arguments-calls)
			fcppt::optional::make(
				fcppt::parse::line_number{
					0U
				}
			)
		}
	);

	parse_one();

	CHECK(
		stream.get_position()
		==
		position{
			offset{} + std::streamoff{1},  // NOLINT(fuchsia-default-arguments-calls)
			fcppt::optional::make(
				fcppt::parse::line_number{
					0U
				}
			)
		}
	);

	parse_one();

	CHECK(
		stream.get_position()
		==
		position{
			offset{} + std::streamoff{2}, // NOLINT(fuchsia-default-arguments-calls)
			fcppt::optional::make(
				fcppt::parse::line_number{
					0U
				}
			)
		}
	);

	parse_one();

	CHECK(
		stream.get_position()
		==
		position{
			offset{} + std::streamoff{3}, // NOLINT(fuchsia-default-arguments-calls)
			fcppt::optional::make(
				fcppt::parse::line_number{
					1U
				}
			)
		}
	);
}
