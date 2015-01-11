//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TRUNCATION_CHECK_HPP_INCLUDED
#define FCPPT_CAST_TRUNCATION_CHECK_HPP_INCLUDED

#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/cast/bad_truncation_check.hpp>
#include <fcppt/cast/detail/truncation_check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Cast between integral types, checking for truncation

\ingroup fcpptcasts

Casts \a _source of type \a Source to the type \a Dest. It returns the
converted value iff the conversion results in no truncation, otherwise
fcppt::cast::bad_truncation_check is thrown.

\tparam Dest Must be an integral type

\tparam Source Must be an integral type

\param _source The source to cast from

\return The casted value if no truncation occurs

\throw fcppt::cast::bad_truncation_check if truncation occurs

\see fcpptcasts_truncation_check
*/
template<
	typename Dest,
	typename Source
>
Dest
truncation_check(
	Source const _source
)
{
	static_assert(
		std::is_integral<
			Source
		>::value
		&&
		std::is_integral<
			Dest
		>::value,
		"truncation_check_cast can only cast from integral to integral types"
	);

	typedef fcppt::optional<
		Dest
	> dest_type;

	dest_type const dest(
		fcppt::cast::detail::truncation_check<
			Dest
		>(
			_source
		)
	);

	if(
		!dest
	)
		throw fcppt::cast::bad_truncation_check(
			fcppt::insert_to_fcppt_string(
				_source
			),
			std::type_index(
				typeid(
					Source
				)
			),
			std::type_index(
				typeid(
					Dest
				)
			)
		);

	return
		*dest;
}

}
}

#endif