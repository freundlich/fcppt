//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_MAKE_EQUAL_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_MAKE_EQUAL_HPP_INCLUDED

#include <fcppt/container/ptr/equal.hpp>

namespace fcppt
{
namespace container
{
namespace ptr
{

/**
\brief Creates a functor that will compare the address of elements in a ptr_container to \p _ptr
\ingroup fcpptcontainerptr

\param _ptr The pointer to compare to

\tparam Ptr Must be a pointer type
*/
template<
	typename Ptr
>
ptr::equal<
	Ptr
> const
make_equal(
	Ptr const _ptr
)
{
	return
		ptr::equal<
			Ptr
		>(
			_ptr
		);
}

}
}
}

#endif
