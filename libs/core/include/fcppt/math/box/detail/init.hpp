//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_MATH_BOX_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/math/box/is_box.hpp>
#include <fcppt/math/detail/init_function.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
namespace detail
{
template <typename Box, typename InitSecond, typename Function>
Box init(InitSecond const &_init_second, Function const &_function)
{
  static_assert(fcppt::math::box::is_box<Box>::value, "Box must be a box::object");

  using value_type = fcppt::type_traits::value_type<Box>;

  using result_array =
      std::array<fcppt::tuple::object<value_type, value_type>, Box::dim_wrapper::value>;

  auto const results(fcppt::container::array::init<result_array>(
      fcppt::math::detail::init_function<Function>(_function)));

  return Box(
      fcppt::math::vector::init<typename Box::vector>([&results](auto const _index) {
        FCPPT_USE(_index);

        return fcppt::tuple::get<0>(std::get<_index()>(results));
      }),
      _init_second([&results](auto const _index) {
        FCPPT_USE(_index);

        return fcppt::tuple::get<1>(std::get<_index()>(results));
      }));
}

}
}
}
}

#endif
