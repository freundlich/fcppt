//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VERSION_STRING_HPP_INCLUDED
#define FCPPT_VERSION_STRING_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief fcppt's version as a string

\ingroup fcpptvarious
*/
FCPPT_DETAIL_SYMBOL
std::string version_string();

}

#endif
