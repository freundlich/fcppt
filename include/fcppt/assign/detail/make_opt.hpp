//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_MAKE_OPT_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_MAKE_OPT_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace assign
{
namespace detail
{

template<
	typename Result,
	typename Arg
>
inline
typename
boost::disable_if<
	fcppt::is_optional<
		typename
		std::remove_const<
			typename
			std::remove_reference<
				Arg
			>::type
		>::type
	>,
	Result
>::type
make_opt(
	Result &&_result,
	Arg &&_arg
)
{
	_result.insert(
		_result.end(),
		std::forward<
			Arg
		>(
			_arg
		)
	);

	return
		std::move(
			_result
		);
}

template<
	typename Result,
	typename Arg
>
inline
typename
boost::enable_if<
	fcppt::is_optional<
		typename
		std::remove_const<
			typename
			std::remove_reference<
				Arg
			>::type
		>::type
	>,
	Result
>::type
make_opt(
	Result &&_result,
	Arg &&_arg
)
{
	return
		_arg.has_value()
		?
			fcppt::assign::detail::make_opt(
				std::move(
					_result
				),
				std::move(
					*_arg
				)
			)
		:
			std::move(
				_result
			)
		;
}

template<
	typename Result,
	typename Arg
>
inline
typename
boost::enable_if<
	fcppt::is_optional<
		typename
		std::remove_const<
			typename
			std::remove_reference<
				Arg
			>::type
		>::type
	>,
	Result
>::type
make_opt(
	Result &&_result,
	Arg const &_arg
)
{
	return
		_arg.has_value()
		?
			fcppt::assign::detail::make_opt(
				std::move(
					_result
				),
				*_arg
			)
		:
			std::move(
				_result
			)
		;
}

}
}
}

#endif