//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_MOVABLE_DECL_HPP_INCLUDED
#define FCPPT_CATCH_MOVABLE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/catch/movable_fwd.hpp>


namespace fcppt
{
namespace catch_
{

/**
\brief A movable-only type.

\ingroup fcpptcatch

This type can be used to test if code also works with types that cannot be copied.
It provides an output and a comparison operator.
*/
template<
	typename Type
>
class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	explicit
	movable(
		Type &&
	);

	movable(
		movable &&
	);

	movable &
	operator=(
		movable &&
	);

	~movable();

	Type &
	value();

	Type const &
	value() const;
private:
	Type value_;
};

}
}

#endif