//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_QUAD_HPP_INCLUDED
#define FCPPT_MATH_QUAD_HPP_INCLUDED

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline T
quad(
	T const &t
)
{
	return t * t;
}

}
}

#endif
