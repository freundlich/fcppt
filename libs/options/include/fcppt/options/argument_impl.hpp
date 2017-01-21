//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_ARGUMENT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_ARGUMENT_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/argument_decl.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/help_text.hpp>
#include <fcppt/options/detail/type_annotation.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label,
	typename Type
>
fcppt::options::argument<
	Label,
	Type
>::argument(
	fcppt::options::long_name const &_long_name,
	fcppt::options::optional_help_text const &_help_text
)
:
	long_name_(
		_long_name
	),
	help_text_{
		_help_text
	}
{
}

template<
	typename Label,
	typename Type
>
fcppt::options::result<
	typename
	fcppt::options::argument<
		Label,
		Type
	>::result_type
>
fcppt::options::argument<
	Label,
	Type
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::either::bind(
			fcppt::either::from_optional(
				_state.pop_arg(),
				[
					this
				]{
					return
						fcppt::options::error{
							fcppt::options::missing_error{
								FCPPT_TEXT("Missing argument \"")
								+
								long_name_.get()
								+
								FCPPT_TEXT('"')
							}
						};
				}
			),
			[
				this
			](
				fcppt::string const &_string
			)
			{
				return
					fcppt::either::from_optional(
						fcppt::optional::map(
							fcppt::extract_from_string<
								Type
							>(
								_string
							),
							[](
								Type &&_value
							)
							{
								return
									result_type{
										Label{} =
											std::move(
												_value
											)
									};
							}
						),
						[
							this,
							&_string
						]{
							return
								fcppt::options::error{
									fcppt::options::other_error{
										FCPPT_TEXT("Failed to convert \"")
										+
										_string
										+
										FCPPT_TEXT("\" to ")
										+
										fcppt::options::pretty_type<
											Type
										>()
										+
										FCPPT_TEXT(" for argument \"")
										+
										long_name_.get()
										+
										FCPPT_TEXT('"')
									}
								};
						}
					);
			}
		);
}

template<
	typename Label,
	typename Type
>
fcppt::options::has_parameter_set
fcppt::options::argument<
	Label,
	Type
>::parameters() const
{
	return
		fcppt::options::has_parameter_set();
}

template<
	typename Label,
	typename Type
>
fcppt::string
fcppt::options::argument<
	Label,
	Type
>::usage() const
{
	return
		long_name_.get()
		+
		fcppt::options::detail::type_annotation<
			Type
		>()
		+
		fcppt::options::detail::help_text(
			help_text_
		);
}

#endif