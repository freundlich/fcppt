//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_INT_TO_FLOAT_FUN_HPP_INCLUDED
#define FCPPT_CAST_INT_TO_FLOAT_FUN_HPP_INCLUDED

#include <fcppt/cast/int_to_float.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Function object of fcppt::cast::int_to_float

\ingroup fcpptcasts
*/
struct int_to_float_fun
{
	template<
		typename Dest,
		typename Source
	>
	Dest
	operator()(
		Source const &_source
	) const
	{
		return
			fcppt::cast::int_to_float<
				Dest
			>(
				_source
			);
	}
};

}
}

#endif
