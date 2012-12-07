//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_DATA_END_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_DATA_END_HPP_INCLUDED


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename Pointer,
	typename Container
>
Pointer
data_end(
	Container &_container
)
{
	return
		_container.empty()
		?
			nullptr
		:
			&_container[0]
			+ _container.size()
		;
}

}
}
}

#endif
