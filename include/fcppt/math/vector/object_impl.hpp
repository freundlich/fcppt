//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/copy.hpp>
#include <fcppt/math/detail/default_storage.hpp>
#include <fcppt/math/detail/index_at.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
>::object()
:
	storage_(
		fcppt::math::detail::default_storage<
			S
		>()
	)
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
>::object(
	fcppt::no_init const &
)
// Don't initialize storage_
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		S
	);
}

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename N,
	typename S
>
template<
	typename ...Args
>
fcppt::math::vector::object<
	T,
	N,
	S
>::object(
	Args const &..._args
)
:
	storage_{{
		_args...
	}}
{
	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		S
	);

	static_assert(
		sizeof...(
			Args
		)
		==
		N::value,
		"Wrong number of parameters"
	);
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
>::object(
	storage_type const &_storage
)
:
	storage_(
		_storage
	)
{
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
>::object(
	object const &
)
= default;

template<
	typename T,
	typename N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::vector::object<
	T,
	N,
	S
>::object(
	fcppt::math::vector::object<
		T,
		N,
		OtherStorage
	> const &_other
)
:
	storage_(
		fcppt::math::detail::copy<
			S
		>(
			_other
		)
	)
{
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
> &
fcppt::math::vector::object<
	T,
	N,
	S
>::operator=(
	object const &
)
= default;

template<
	typename T,
	typename N,
	typename S
>
template<
	typename OtherStorage
>
fcppt::math::vector::object<
	T,
	N,
	S
> &
fcppt::math::vector::object<
	T,
	N,
	S
>::operator=(
	fcppt::math::vector::object<
		T,
		N,
		OtherStorage
	> const &_other
)
{
	return
		fcppt::math::detail::assign(
			*this,
			_other
		);
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
>::~object()
{
}

#define FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	3,\
	(template<typename T, typename N, typename S> template<typename OtherStorage>),\
	(fcppt::math::vector::object<T, N, S>),\
	(fcppt::math::vector::object<T, N, OtherStorage>),\
	op\
)

FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(+=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(-=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(*=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(/=)
FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR(%=)

#undef FCPPT_MATH_VECTOR_OBJECT_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
> &
fcppt::math::vector::object<
	T,
	N,
	S
>::operator*=(
	value_type const &_value
)
{
	for(
		auto &item
		:
		storage_
	)
		item *=
			_value;

	return
		*this;
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<
	T,
	N,
	S
> &
fcppt::math::vector::object<
	T,
	N,
	S
>::operator/=(
	value_type const &_value
)
{
	for(
		auto &item
		:
		storage_
	)
		item /=
			_value;

	return
		*this;
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<
	T,
	N,
	S
>::const_reference
fcppt::math::vector::object<
	T,
	N,
	S
>::operator[](
	size_type const _index
) const
{
	return
		fcppt::math::detail::index_at(
			storage_,
			_index
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::vector::object<
	T,
	N,
	S
>::reference
fcppt::math::vector::object<
	T,
	N,
	S
>::operator[](
	size_type const _index
)
{
	return
		fcppt::math::detail::index_at(
			storage_,
			_index
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::reference
fcppt::math::vector::object<
	T,
	N,
	S
>::x()
{
	return
		fcppt::math::detail::checked_access<
			0
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::const_reference
fcppt::math::vector::object<
	T,
	N,
	S
>::x() const
{
	return
		fcppt::math::detail::checked_access<
			0
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::reference
fcppt::math::vector::object<
	T,
	N,
	S
>::y()
{
	return
		fcppt::math::detail::checked_access<
			1
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::const_reference
fcppt::math::vector::object<
	T,
	N,
	S
>::y() const
{
	return
		fcppt::math::detail::checked_access<
			1
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::reference
fcppt::math::vector::object<
	T,
	N,
	S
>::z()
{
	return
		fcppt::math::detail::checked_access<
			2
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::const_reference
fcppt::math::vector::object<
	T,
	N,
	S
>::z() const
{
	return
		fcppt::math::detail::checked_access<
			2
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::reference
fcppt::math::vector::object<
	T,
	N,
	S
>::w()
{
	return
		fcppt::math::detail::checked_access<
			3
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::vector::object<
	T,
	N,
	S
>::const_reference
fcppt::math::vector::object<
	T,
	N,
	S
>::w() const
{
	return
		fcppt::math::detail::checked_access<
			3
		>(
			*this
		);
}

template<
	typename T,
	typename N,
	typename S
>
S &
fcppt::math::vector::object<
	T,
	N,
	S
>::storage()
{
	return
		storage_;
}

template<
	typename T,
	typename N,
	typename S
>
S const &
fcppt::math::vector::object<
	T,
	N,
	S
>::storage() const
{
	return
		storage_;
}

#endif
