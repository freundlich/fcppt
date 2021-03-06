//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(fcppt::type_traits::is_string<std::string>::value);

  static_assert(fcppt::type_traits::is_string<std::wstring>::value);

  static_assert(!fcppt::type_traits::is_string<int>::value);
}
