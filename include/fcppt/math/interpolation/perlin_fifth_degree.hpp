//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERPOLATION_PERLIN_FIFTH_DEGREE_HPP_INCLUDED
#define FCPPT_MATH_INTERPOLATION_PERLIN_FIFTH_DEGREE_HPP_INCLUDED

#include <fcppt/math/interpolation/linear.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace interpolation
{
/// Interpolates between a and b (works only with a floating point
/// parameter)
template<typename Float,typename Value>
typename
boost::enable_if
<
	std::is_floating_point<Float>,
	Value const
>::type
perlin_fifth_degree(
	Float const &f,
	Value const &v1,
	Value const &v2)
{
	return
		fcppt::math::interpolation::linear(
			f * f * f * (f * (static_cast<Float>(6.0f) * f - static_cast<Float>(15.0f)) + static_cast<Float>(10.0f)),
			v1,
			v2);
}
}
}
}

#endif

