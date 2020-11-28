//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/variant/dynamic_cast_types.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using types = fcppt::variant::dynamic_cast_types<metal::list<int, char const>>;

  static_assert(std::is_same_v<metal::at<types, metal::number<0>>, fcppt::reference<int>>);

  static_assert(std::is_same_v<metal::at<types, metal::number<1>>, fcppt::reference<char const>>);
}
