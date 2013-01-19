//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_IS_MATRIX_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IS_MATRIX_HPP_INCLUDED

#include <fcppt/math/matrix/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to test if a type is a matrix type
\ingroup fcpptmathmatrix
\tparam T The type to test against
*/
template
<
	typename T
>
struct is_matrix
:
	boost::mpl::false_
{
};

/// \cond FCPPT_DOXYGEN_DEBUG
template
<
	typename T,
	typename N,
	typename M,
	typename S
>
struct is_matrix
<
	matrix::object<T,N,M,S>
>
:
	boost::mpl::true_
{
};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
