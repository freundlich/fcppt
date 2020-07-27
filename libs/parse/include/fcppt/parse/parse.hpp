//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_PARSE_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/context_impl.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/is_skipper.hpp>
#include <fcppt/parse/is_valid_argument.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/run_skipper.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch,
	typename Parser,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	fcppt::parse::result_of<
		Parser
	>
>
parse(
	Parser const &_parser,
	fcppt::parse::basic_stream<
		Ch
	> &_input,
	Skipper const &_skipper
)
try
{
	static_assert(
		fcppt::parse::is_valid_argument<
			Parser
		>::value
	);

	static_assert(
		fcppt::parse::is_skipper<
			Skipper
		>::value
	);

	fcppt::parse::state<
		Ch
	> state{
		fcppt::make_ref(
			_input
		)
	};

	fcppt::parse::context<
		Skipper
	> const context{
		fcppt::make_cref(
			_skipper
		)
	};

	return
		fcppt::either::bind(
			fcppt::parse::run_skipper(
				fcppt::make_ref(
					state
				),
				context
			),
			[
				&context,
				&state,
				&_parser
			](
				fcppt::unit const &
			)
			{
				return
					_parser.parse(
						fcppt::make_ref(
							state
						),
						context
					);
			}
		);
}
catch(
	fcppt::parse::detail::exception<
		Ch
	> const &_error
)
{
	return
		fcppt::either::make_failure<
			fcppt::parse::result_of<
				Parser
			>
		>(
			fcppt::parse::error<
				Ch
			>{
				std::basic_string<
					Ch
				>{
					FCPPT_STRING_LITERAL(
						Ch,
						"Parsing failed: "
					)
				}
				+
				_error.what()
			}
		);
}

}
}

#endif