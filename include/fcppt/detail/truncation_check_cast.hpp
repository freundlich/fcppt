//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_DETAIL_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/utility/enable_if.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::equal_to<
			boost::is_signed<
				Dest
			>,
			boost::is_signed<
				Source
			>
		>,
		boost::mpl::greater_equal<
			boost::mpl::sizeof_<
				Dest
			>,
			boost::mpl::sizeof_<
				Source
			>
		>
	>,
	fcppt::optional<
		Dest
	>
>::type
truncation_check_cast(
	Source const _source
)
{
	return
		fcppt::optional<
			Dest
		>(
			_source
		);
}

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_unsigned<
			Dest
		>,
		std::is_unsigned<
			Source
		>,
		boost::mpl::less<
			boost::mpl::sizeof_<
				Dest
			>,
			boost::mpl::sizeof_<
				Source
			>
		>
	>,
	fcppt::optional<
		Dest
	>
>::type
truncation_check_cast(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	return
		fcppt::cast::size<
			Source
		>(
			std::numeric_limits<
				Dest
			>::max()
		)
		<
		_source
		?
			dest_type()
		:
			dest_type(
				fcppt::cast::size<
					Dest
				>(
					_source
				)
			)
		;
}

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_signed<
			Dest
		>,
		std::is_signed<
			Source
		>,
		boost::mpl::less<
			boost::mpl::sizeof_<
				Dest
			>,
			boost::mpl::sizeof_<
				Source
			>
		>
	>,
	fcppt::optional<
		Dest
	>
>::type
truncation_check_cast(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	return
		fcppt::cast::size<
			Source
		>(
			std::numeric_limits<
				Dest
			>::max()
		)
		<
		_source
		||
		fcppt::cast::size<
			Source
		>(
			std::numeric_limits<
				Dest
			>::min()
		)
		>
		_source
		?
			dest_type()
		:
			dest_type(
				fcppt::cast::size<
					Dest
				>(
					_source
				)
			)
		;
}

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_unsigned<
			Dest
		>,
		std::is_signed<
			Source
		>
	>,
	fcppt::optional<
		Dest
	>
>::type
truncation_check_cast(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	return
		_source
		<
		fcppt::literal<
			Source
		>(
			0
		)
		?
			dest_type()
		:
			fcppt::detail::truncation_check_cast<
				Dest
			>(
				fcppt::cast::to_unsigned(
					_source
				)
			);
}

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		std::is_signed<
			Dest
		>,
		std::is_unsigned<
			Source
		>
	>,
	fcppt::optional<
		Dest
	>
>::type
truncation_check_cast(
	Source const _source
)
{
	typedef fcppt::optional<
		Dest
	> dest_type;

	typedef typename std::make_unsigned<
		Dest
	>::type intermediate_type;

	typedef fcppt::optional<
		intermediate_type
	> intermediate_dest;

	intermediate_dest const dest(
		fcppt::detail::truncation_check_cast<
			intermediate_type
		>(
			_source
		)
	);

	return
		!dest
		||
		fcppt::cast::to_unsigned(
			std::numeric_limits<
				Dest
			>::max()
		)
		<
		*dest
		?
			dest_type()
		:
			dest_type(
				fcppt::cast::size<
					Dest
				>(
					fcppt::cast::to_signed(
						_source
					)
				)
			);
}

}
}

#endif
