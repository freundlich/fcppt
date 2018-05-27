//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MULTIPLY_SCALAR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MULTIPLY_SCALAR_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_brigand.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/detail/storage_size.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Storage
>
void
multiply_scalar(
	Storage &_value,
	typename
	Storage::value_type const _mult
)
{
	fcppt::algorithm::loop(
		fcppt::math::int_range_count<
			fcppt::math::detail::storage_size<
				Storage
			>::value
		>{},
		[
			&_value,
			_mult
		](
			auto const _index
		)
		{
			FCPPT_USE(
				_index
			);

			typedef
			fcppt::tag_type<
				decltype(
					_index
				)
			>
			index;

			_value[
				index()
			] *=
				_mult;
		}
	);
}

}
}
}

#endif