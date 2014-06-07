//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ENABLE_OPTIONAL_VALUE_CONV_HPP_INCLUDED
#define FCPPT_DETAIL_ENABLE_OPTIONAL_VALUE_CONV_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Own,
	typename Other,
	typename Result
>
struct enable_optional_value_conv
:
boost::enable_if<
	boost::mpl::and_<
		std::is_reference<
			Other
		>,
		std::is_same<
			Own,
			typename fcppt::type_traits::remove_cv_ref<
				Other
			>::type
		>
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
