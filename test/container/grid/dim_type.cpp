//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/dim_type.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using grid = fcppt::container::grid::object<int, 2>;

  static_assert(std::is_same_v<
                fcppt::container::grid::dim_type<grid>,
                fcppt::container::grid::dim<grid::size_type, 2>>);
}
