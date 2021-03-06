//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/range_element_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<fcppt::algorithm::range_element_type<std::vector<int>>, int &>);

  static_assert(
      std::is_same_v<fcppt::algorithm::range_element_type<std::vector<int> const>, int const &>);
}
