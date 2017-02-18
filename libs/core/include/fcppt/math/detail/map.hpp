//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAP_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAP_HPP_INCLUDED

#include <fcppt/algorithm/array_map.hpp>
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/to_array.hpp>
#include <fcppt/math/to_array_type.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Source,
	typename Function
>
inline
Dest
map(
	Source const &_source,
	Function const &_function
)
{
	return
		fcppt::math::from_array<
			Dest
		>(
			fcppt::algorithm::array_map<
				fcppt::math::to_array_type<
					Dest
				>
			>(
				fcppt::math::to_array(
					_source
				),
				_function
			)
		);
}

}
}
}

#endif