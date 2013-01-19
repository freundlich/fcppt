//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_IS_SUBSET_EQ_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_IS_SUBSET_EQ_HPP_INCLUDED

#include <fcppt/container/bitfield/object_impl.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Checks if one bitfield has all the bits of another bitfield set.
\param left The "bigger" bitfield
\param right The "smaller" bitfield
*/
template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
is_subset_eq(
	fcppt::container::bitfield::object<
		Enum,
		Size,
		InternalType
	> const &left,
	fcppt::container::bitfield::object<
		Enum,
		Size,
		InternalType
	> const &right
)
{
	return
		(left & right)
		== left;
}

}
}
}

#endif
