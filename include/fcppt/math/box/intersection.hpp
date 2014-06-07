//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/intersects.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Calculates the intersection of two boxes (which is, again, a box)
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

If there is no intersection, the null box will be returned.
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
> const
intersection(
	fcppt::math::box::object<
		T,
		N
	> const &_a,
	fcppt::math::box::object<
		T,
		N
	> const &_b
)
{
	typedef
	fcppt::math::box::object<
		T,
		N
	> result_type;

	if(
		!fcppt::math::box::intersects(
			_a,
			_b
		)
	)
		return result_type::null();

	result_type ret{
		fcppt::no_init()
	};

	for(
		size_type i = 0;
		i < N;
		++i
	)
	{
		ret.pos(
			i,
			std::max(
				_a.pos(i),
				_b.pos(i)
			)
		);

		ret.size(
			i,
			std::min(
				_a.max(i),
				_b.max(i)
			)
			- ret.pos(i)
		);
	}

	return ret;
}

}
}
}

#endif
