//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/reference_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<fcppt::optional::reference_type<fcppt::optional::object<int>>, int &>);
  static_assert(std::is_same_v<fcppt::optional::reference_type<fcppt::optional::object<int> const>, int const &>);
}