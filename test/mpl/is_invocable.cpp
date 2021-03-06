//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/is_invocable.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

int main()
{
  struct F
  {
    void operator()(int) const {}
  };

//  static_assert(std::is_invocable<F,int>::value);
  static_assert(fcppt::mpl::is_invocable<F, fcppt::mpl::list::object<int>>::value);
  static_assert(!fcppt::mpl::is_invocable<F, fcppt::mpl::list::object<std::string>>::value);

  F const f{};
  f(10);
}
