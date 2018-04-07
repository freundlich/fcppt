//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/detail/map_reserve.hpp>
#include <fcppt/container/array/map.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename TargetContainer,
	typename SourceRange,
	typename Function
>
std::enable_if_t<
	!fcppt::type_traits::is_std_array<
		TargetContainer
	>::value,
	TargetContainer
>
map(
	SourceRange &&_source,
	Function const &_function
)
{
	TargetContainer result;

	fcppt::algorithm::detail::map_reserve(
		result,
		_source
	);

	fcppt::algorithm::loop(
		std::forward<
			SourceRange
		>(
			_source
		),
		[
			&_function,
			&result
		](
			auto &&_map_element
		)
		{
			result.insert(
				result.end(),
				_function(
					fcppt::move_if_rvalue<
						SourceRange
					>(
						_map_element
					)
				)
			);
		}
	);

	return
		result;
}

template<
	typename TargetContainer,
	typename SourceRange,
	typename Function
>
std::enable_if_t<
	fcppt::type_traits::is_std_array<
		TargetContainer
	>::value,
	TargetContainer
>
map(
	SourceRange &&_source,
	Function const &_function
)
{
	return
		fcppt::container::array::map(
			std::forward<
				SourceRange
			>(
				_source
			),
			_function
		);
}

}
}
}

#endif
