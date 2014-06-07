//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CENTER_HPP_INCLUDED
#define FCPPT_MATH_BOX_CENTER_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{
/**
\brief Returns the center of the box
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

Note that this might not calculate the box's "real" center, since the
calculation is performed using <code>T</code>, which might be integral.
*/
template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::vector const
center(
	fcppt::math::box::object<
		T,
		N
	> const &b)
{
	return
		b.pos() +
		fcppt::math::dim::structure_cast<
			typename fcppt::math::box::object
			<
				T,
				N
			>::vector
		>(
			b.size()
		)
		/
		fcppt::literal<
			T
		>(
			2
		);
}
}
}
}

#endif
