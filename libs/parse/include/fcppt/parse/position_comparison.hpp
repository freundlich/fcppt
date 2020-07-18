//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_POSITION_COMPARISON_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_COMPARISON_HPP_INCLUDED

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/parse/position_impl.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
bool
operator==(
	fcppt::parse::position<
		Ch
	> const &_left,
	fcppt::parse::position<
		Ch
	> const &_right
)
{
	return
		_left.pos() == _right.pos()
		&&
		_left.line() == _right.line();
}

}
}

#endif
