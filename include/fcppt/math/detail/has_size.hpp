//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_HAS_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_HAS_SIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	fcppt::math::size_type N
>
struct has_size
:
std::is_same<
	T,
	typename fcppt::math::static_size<
		N
	>::type
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
