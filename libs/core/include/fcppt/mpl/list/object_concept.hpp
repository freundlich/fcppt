//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_OBJECT_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_LIST_OBJECT_CONCEPT_HPP_INCLUDED

#include <fcppt/mpl/list/is_object.hpp>

namespace fcppt::mpl::list
{

/**
\brief Concept for lists.
\ingroup fcpptmpl
\see fcppt::mpl::list::is_object
*/
template<typename T>
concept object_concept = fcppt::mpl::list::is_object<T>::value;

}

#endif
