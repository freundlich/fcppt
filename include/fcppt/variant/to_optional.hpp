//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_TO_OPTIONAL_HPP_INCLUDED
#define FCPPT_VARIANT_TO_OPTIONAL_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/detail/to_optional_result.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Converts a variant and a type to an optional

\ingroup fcpptvariant
*/
template<
	typename Type,
	typename Variant
>
fcppt::optional<
	fcppt::variant::detail::to_optional_result<
		Type,
		Variant
	>
>
to_optional(
	Variant &&_variant
)
{
	typedef
	fcppt::optional<
		fcppt::variant::detail::to_optional_result<
			Type,
			Variant
		>
	>
	result_type;

	return
		fcppt::variant::holds_type<
			Type
		>(
			_variant
		)
		?
			result_type{
				fcppt::move_if_rvalue<
					Variant
				>(
					_variant. template get_unsafe<
						Type
					>()
				)
			}
		:
			result_type{}
		;
}

}
}

#endif
