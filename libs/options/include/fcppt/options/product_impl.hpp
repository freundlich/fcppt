//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/set_union.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/product_decl.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/combine_errors.hpp>
#include <fcppt/options/detail/deref.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/multiply_disjoint.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	Left const &_left,
	Right const &_right
)
:
	left_(
		_left
	),
	right_(
		_right
	)
{
}

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	Left &&_left,
	Right &&_right
)
:
	left_(
		std::move(
			_left
		)
	),
	right_(
		std::move(
			_right
		)
	)
{
}

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	product const &
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::product(
	product &&
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
> &
fcppt::options::product<
	Left,
	Right
>::operator=(
	product const &
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
> &
fcppt::options::product<
	Left,
	Right
>::operator=(
	product &&
)
= default;

template<
	typename Left,
	typename Right
>
fcppt::options::product<
	Left,
	Right
>::~product()
{
}

template<
	typename Left,
	typename Right
>
fcppt::options::result<
	typename
	fcppt::options::product<
		Left,
		Right
	>::result_type
>
fcppt::options::product<
	Left,
	Right
>::parse(
	fcppt::options::state &_state
) const
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
	return
		fcppt::either::match(
			fcppt::options::detail::deref(
				left_
			).parse(
				_state
			),
			[
				&_state,
				this
			](
				fcppt::options::error &&_error
			)
			{
				return
					fcppt::options::result<
						result_type
					>{
						fcppt::optional::maybe(
							fcppt::either::failure_opt(
								fcppt::options::detail::deref(
									right_
								).parse(
									_state
								)
							),
							[
								&_error
							]()
							->
							fcppt::options::error
							{
								return
									std::move(
										_error
									);
							},
							[
								&_error
							](
								fcppt::options::error &&_other_error
							)
							->
							fcppt::options::error
							{
								return
									fcppt::options::detail::combine_errors(
										std::move(
											_error
										),
										std::move(
											_other_error
										)
									);
							}
						)
					};
			},
			[
				&_state,
				this
			](
				fcppt::options::result_of<
					Left
				> &&_left_result
			)
			{
				return
					fcppt::either::map(
						fcppt::options::detail::deref(
							right_
						).parse(
							_state
						),
						[
							&_left_result
						](
							fcppt::options::result_of<
								Right
							> &&_right_result
						)
						{
							return
								fcppt::record::multiply_disjoint(
									std::move(
										_left_result
									),
									std::move(
										_right_result
									)
								);
						}
					);
			}
		);
FCPPT_PP_POP_WARNING
}

template<
	typename Left,
	typename Right
>
fcppt::options::has_parameter_set
fcppt::options::product<
	Left,
	Right
>::parameters() const
{
	return
		fcppt::algorithm::set_union(
			fcppt::options::detail::deref(
				left_
			).parameters(),
			fcppt::options::detail::deref(
				right_
			).parameters()
		);
}

template<
	typename Left,
	typename Right
>
fcppt::string
fcppt::options::product<
	Left,
	Right
>::usage() const
{
	return
		fcppt::options::detail::deref(
			left_
		).usage()
		+
		FCPPT_TEXT('\n')
		+
		fcppt::options::detail::deref(
			right_
		).usage();
}

#endif
