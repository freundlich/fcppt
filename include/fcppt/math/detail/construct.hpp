//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
inline
Dest
construct(
	Src const &_src,
	typename Src::value_type const &_value
)
{
	static_assert(
		Dest::static_size::value
		==
		Src::static_size::value
		+
		1u,
		""
	);

	Dest ret{
		fcppt::no_init()
	};

	for(
		auto const index
		:
		fcppt::make_int_range_count(
			Src::static_size::value
		)
	)
		ret[
			index
		] =
			_src[
				index
			];

	ret[
		Src::static_size::value
	] =
		_value;

	return
		ret;
}

}
}
}

#endif
