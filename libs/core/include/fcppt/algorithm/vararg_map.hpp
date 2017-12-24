//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_VARARG_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/untuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Map a std::tuple to variadic arguments.

\ingroup fcpptalgorithm

Let \a _tuple be <code>(v_1,...,v_n)</code>. The result is
<code>_anchor(_element(v_1),...,_element(v_n))</code>.

\tparam Tuple A std::tuple.
*/
template<
	typename Tuple,
	typename AnchorFunction,
	typename ElementFunction
>
inline
decltype(
	auto
)
vararg_map(
	Tuple &&_tuple,
	AnchorFunction const &_anchor,
	ElementFunction const &_element
)
{
	return
		fcppt::container::untuple(
			std::forward<
				Tuple
			>(
				_tuple
			),
			[
				&_anchor,
				&_element
			](
				auto &&... _args
			)
			{
				return
					_anchor(
						_element(
							fcppt::move_if_rvalue<
								Tuple
							>(
								_args
							)
						)...
					);
			}
		);
}

}
}

#endif
