//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_FOLD_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_FOLD_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Result,
	typename Function
>
class array_fold_function
{
	FCPPT_NONASSIGNABLE(
		array_fold_function
	);
public:
	explicit
	array_fold_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	template<
		std::size_t Index
	>
	Result
	operator()() const
	{
		return
			function_(
				Index
			);
	}
private:
	Function const &function_;
};

}
}
}

#endif