// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED

#include <fcppt/null_ptr.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/detail/rvalue_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/common_type.hpp>
#include <algorithm>
#include <functional>
#include <fcppt/config/external_end.hpp>


// doxygen says: warning: member `operator fcppt::detail_rv' of class `unique_ptr' cannot be found
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::
operator fcppt::detail::rvalue_ref<
	fcppt::unique_ptr<
		Type,
		Deleter
	>
>()
{
	return
		fcppt::detail::rvalue_ref<
			unique_ptr
		>(
			*this
		);
}
/// \endcond

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	fcppt::detail::rvalue_ref<
		unique_ptr
	> _other
)
:
	ptr_(
		_other->release()
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
> &
fcppt::unique_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::detail::rvalue_ref<
		unique_ptr
	> _other
)
{
	this->reset(
		_other->release()
	);

        return *this;
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr()
:
	ptr_(
		fcppt::null_ptr()
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	pointer const _ptr
)
:
	ptr_(
		_ptr
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _other
)
:
	ptr_(
		_other.release()
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::~unique_ptr()
{
	this->reset();
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::unique_ptr<
	Type,
	Deleter
> &
fcppt::unique_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _other
)
{
	this->reset(
		_other.release()
	);

	return *this;
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::reference
fcppt::unique_ptr<
	Type,
	Deleter
>::operator*() const
{
	return *this->get();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::operator->() const
{
	return this->get();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::get() const
{
	return ptr_;
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::unique_ptr<
	Type,
	Deleter
>::reset()
{
	Deleter()(
		ptr_
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
void
fcppt::unique_ptr<
	Type,
	Deleter
>::reset(
	Other *const _ptr
)
{
	this->reset();

	ptr_ = _ptr;
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::release()
{
	pointer const this_ptr(
		this->get()
	);

	ptr_ = fcppt::null_ptr();

	return this_ptr;
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::unique_ptr<
	Type,
	Deleter
>::swap(
	unique_ptr &_other
)
{
	std::swap(
		ptr_,
		_other.ptr_
	);
}

template<
	typename Type,
	typename Deleter
>
bool
fcppt::unique_ptr<
	Type,
	Deleter
>::boolean_test() const
{
	return
		ptr_
		!=
		fcppt::null_ptr();
}

template<
	typename Type,
	typename Deleter
>
inline
void
fcppt::swap(
	fcppt::unique_ptr<
		Type,
		Deleter
	> &_left,
	fcppt::unique_ptr<
		Type,
		Deleter
	> &_right
)
{
	_left.swap(
		_right
	);
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator==(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		_left.get()
		==
		_right.get();
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator!=(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		!(
			_left
			==
			_right
		);
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator<(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		std::less<
			typename boost::common_type<
				Type1 *,
				Type2 *
			>::type
		>()(
			_left.get(),
			_right.get()
		);
}

#endif
