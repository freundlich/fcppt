//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_APPLY_RESULT_AT_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_APPLY_RESULT_AT_HPP_INCLUDED

#include <fcppt/tuple/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple::detail
{
template <typename Function, std::size_t Index, typename... Tuples>
using apply_result_at =
    std::invoke_result_t<Function,decltype(fcppt::tuple::get<Index>(std::declval<Tuples>()))...>;

}

#endif
