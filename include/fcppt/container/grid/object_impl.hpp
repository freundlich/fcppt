//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/detail/access_member.hpp>
#include <fcppt/container/grid/detail/at.hpp>
#include <fcppt/container/grid/detail/resize.hpp>
#include <fcppt/container/grid/detail/shrink_to_fit.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object()
:
	container_(),
	size_(
		dim::null()
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object(
	dim const &_size
)
:
	container_(
		_size.content()
	),
	size_(
		_size
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object(
	dim const &_size,
	const_reference _value
)
:
	container_(
		_size.content(),
		_value
	),
	size_(
		_size
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
template<
	typename In
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object(
	dim const &_size,
	In const _begin,
	In const _end
)
:
	container_(
		_begin,
		_end
	),
	size_(
		_size
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
template<
	typename Range
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object(
	dim const &_size,
	Range const &_range
)
:
	object(
		_size,
		_range.begin(),
		_range.end()
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object(
	object const &_other
)
:
	container_(
		_other.container_
	),
	size_(
		_other.size_
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
>::object(
	object &&_other
)
:
	container_(
		std::move(
			_other.container_
		)
	),
	size_(
		_other.size_
	)
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
> &
fcppt::container::grid::object<
	T,
	N,
	A
>::operator=(
	object const &_other
)
{
	if(
		&_other == this
	)
		return *this;

	container_ = _other.container_;

	size_ = _other.size_;

	return *this;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
> &
fcppt::container::grid::object<
	T,
	N,
	A
>::operator=(
	object &&_other
)
{
	if(
		&_other == this
	)
		return *this;

	container_ =
		std::move(
			_other.container_
		);

	size_ = _other.size_;

	return *this;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
fcppt::container::grid::object<
	T,
	N,
	A
>::~object()
{
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::reference
fcppt::container::grid::object<
	T,
	N,
	A
>::operator[](
	pos const &_pos
)
{
	return
		fcppt::container::grid::detail::access_member(
			container_,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_reference
fcppt::container::grid::object<
	T,
	N,
	A
>::operator[](
	pos const &_pos
) const
{
	return
		fcppt::container::grid::detail::access_member(
			container_,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::reference
fcppt::container::grid::object<
	T,
	N,
	A
>::at(
	pos const &_pos
)
{
	return
		fcppt::container::grid::detail::at(
			*this,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_reference
fcppt::container::grid::object<
	T,
	N,
	A
>::at(
	pos const &_pos
) const
{
	return
		fcppt::container::grid::detail::at(
			*this,
			size_,
			_pos
		);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::dim const &
fcppt::container::grid::object<
	T,
	N,
	A
>::size() const
{
	return size_;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::size_type
fcppt::container::grid::object<
	T,
	N,
	A
>::content() const
{
	return size_.content();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
fcppt::container::grid::object<
	T,
	N,
	A
>::empty() const
{
	return size_.empty();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<
	T,
	N,
	A
>::resize(
	dim const &_size
)
{
	fcppt::container::grid::detail::resize(
		container_,
		_size
	);

	size_ = _size;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<
	T,
	N,
	A
>::resize_init(
	dim const &_size,
	T const &_value
)
{
	container_.resize(
		_size.content(),
		_value
	);

	size_ = _size;
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<
	T,
	N,
	A
>::shrink_to_fit()
{
	fcppt::container::grid::detail::shrink_to_fit(
		container_
	);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::pointer
fcppt::container::grid::object<
	T,
	N,
	A
>::data()
{
	return
		container_.data();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_pointer
fcppt::container::grid::object<
	T,
	N,
	A
>::data() const
{
	return
		container_.data();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::pointer
fcppt::container::grid::object<
	T,
	N,
	A
>::data_end()
{
	return
		container_.data()
		+
		this->content();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_pointer
fcppt::container::grid::object<
	T,
	N,
	A
>::data_end() const
{
	return
		container_.data()
		+
		this->content();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::begin()
{
	return container_.begin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::begin() const
{
	return container_.begin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::cbegin() const
{
	return container_.begin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::end()
{
	return container_.end();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::end() const
{
	return container_.end();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::cend() const
{
	return container_.end();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::reverse_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::rbegin()
{
	return container_.rbegin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_reverse_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::rbegin() const
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_reverse_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::crbegin() const
{
	return container_.rbegin();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::reverse_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::rend()
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_reverse_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::rend() const
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename fcppt::container::grid::object<
	T,
	N,
	A
>::const_reverse_iterator
fcppt::container::grid::object<
	T,
	N,
	A
>::crend() const
{
	return container_.rend();
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::object<
	T,
	N,
	A
>::swap(
	object &_other
)
{
	container_.swap(
		_other.container_
	);

	size_.swap(
		_other.size_
	);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
fcppt::container::grid::swap(
	fcppt::container::grid::object<
		T,
		N,
		A
	> &_a,
	fcppt::container::grid::object<
		T,
		N,
		A
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
