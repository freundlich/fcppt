//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_MAP_RESULT_HPP_INCLUDED
#define FCPPT_TUPLE_MAP_RESULT_HPP_INCLUDED

#include <fcppt/tuple/size.hpp>
#include <fcppt/tuple/detail/map_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief The result type of #fcppt::tuple::map.

\ingroup fcppttuple
*/
template <typename Tuple, typename Function>
using map_result = typename fcppt::tuple::detail::map_result<
    std::make_index_sequence<fcppt::tuple::size<std::remove_cvref_t<Tuple>>::value>,
    Tuple,
    std::remove_cvref_t<Function>>::type;

}

#endif
