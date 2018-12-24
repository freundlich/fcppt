//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SEQUENCE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/sequence_decl.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/detail/flatten_tuples.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename Right
>
fcppt::parse::sequence<
	Left,
	Right
>::sequence(
	Left &&_left,
	Right &&_right
)
:
	left_{
		std::move(
			_left
		)
	},
	right_{
		std::move(
			_right
		)
	}
{
}

template<
	typename Left,
	typename Right
>
template<
	typename Skipper
>
fcppt::parse::result<
	typename
	fcppt::parse::sequence<
		Left,
		Right
	>::result_type
>
fcppt::parse::sequence<
	Left,
	Right
>::parse(
	fcppt::reference<
		fcppt::parse::state
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &_context
) const
{
	return
		fcppt::optional::bind(
			fcppt::parse::deref(
				this->left_
			).parse(
				_state,
				_context
			),
			[
				&_state,
				&_context,
				this
			](
				fcppt::parse::result_of<
					Left
				> &&_left_result
			)
			{
				return
					fcppt::optional::map(
						fcppt::parse::deref(
							this->right_
						).parse(
							_state,
							_context
						),
						[
							&_left_result
						](
							fcppt::parse::result_of<
								Right
							> &&_right_result
						)
						{
							return
								fcppt::parse::detail::flatten_tuples(
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
}

#endif
