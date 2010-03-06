//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIELD_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_FIELD_DECL_HPP_INCLUDED

#include <fcppt/container/field_fwd.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <iterator>
#include <iosfwd>

//[field_decl
namespace fcppt
{
namespace container
{

template<
	typename ArrayType
>
class field
{
public:
	typedef ArrayType                             array_type;

	typedef typename ArrayType::value_type        value_type;
	typedef typename ArrayType::allocator_type    allocator_type;
	typedef typename ArrayType::reference         reference;
	typedef typename ArrayType::const_reference   const_reference;
	typedef typename array_type::iterator         iterator;
	typedef typename array_type::const_iterator   const_iterator;
	typedef typename array_type::size_type        size_type;
	typedef typename array_type::difference_type  difference_type;
	typedef std::reverse_iterator<iterator>       reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef value_type scalar;
	typedef typename math::vector::static_<size_type,2>::type      vector;
	typedef typename math::dim::static_<size_type,2>::type         dim;

	explicit field(
		allocator_type const &alloc = allocator_type()
	);

	field(
		field const &r
	);

	explicit field(
		dim const &,
		value_type const & = value_type(),
		allocator_type const & = allocator_type()
	);

	template<
		typename Iterator
	>
	field(
		dim const &,
		Iterator begin,
		Iterator end,
		allocator_type const & = allocator_type()
	);

	void
	swap(
		field &r
	);

	field &
	operator=(
		field const &
	);

	size_type
	size() const;

	size_type
	max_size() const;

	bool
	empty() const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	reverse_iterator
	rend();

	const_reverse_iterator
	rbegin() const;

	const_reverse_iterator
	rend() const;

	vector const
	position(
		const_iterator it
	) const;

	iterator
	position_it(
		vector const &
	);

	const_iterator
	position_it(
		vector const &
	) const;

	allocator_type
	get_allocator() const;

	void
	resize_canvas(
		dim const &,
		const_reference = value_type()
	);

	void
	resize(
		dim const &,
		const_reference = value_type()
	);

	value_type &
	pos_mod(
		vector const &
	);

	value_type const &
	pos_mod(
		vector const &
	) const;

	value_type &
	pos(
		vector const &
	);

	value_type const &
	pos(
		vector const &
	) const;

	reference
	front();

	const_reference
	front() const;

	reference
	back();

	const_reference
	back() const;

	value_type
	x(
		const_iterator
	) const;

	value_type
	y(
		const_iterator
	) const;

	vector const
	pos(
		const_iterator p
	) const;

	dim const
	dimension() const;
//<-
private:
	void
	range_check(
		vector const &
	) const;

	void
	check_w() const;

	dim dimension_;
	array_type array;
//->
};


template<
	typename ArrayType
>
bool
operator==(
	field<ArrayType> const &,
	field<ArrayType> const &
);

template<
	typename ArrayType
>
bool
operator!=(
	field<ArrayType> const &l,
	field<ArrayType> const &r
);

template<
	typename ArrayType,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch, Traits> &
operator<<(
	std::basic_ostream<Ch, Traits> &,
	field<ArrayType> const &
);

}
}
//]

#endif
