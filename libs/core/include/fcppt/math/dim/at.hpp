//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_AT_HPP_INCLUDED
#define FCPPT_MATH_DIM_AT_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/dim/is_dim.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Access an element using a compile-time constant

\ingroup fcpptmathdim

\tparam Dim Must be an \link fcppt::math::dim::object\endlink.
*/
template<
	fcppt::math::size_type Index,
	typename Dim
>
inline
fcppt::container::to_reference_type<
	typename
	std::remove_reference<
		Dim
	>::type
>
at(
	Dim &_value
)
{
	static_assert(
		fcppt::math::dim::is_dim<
			typename
			std::decay<
				Dim
			>::type
		>::value,
		"Dim must be a dim"
	);

	return
		fcppt::math::detail::checked_access<
			Index
		>(
			_value
		);
}

}
}
}

#endif