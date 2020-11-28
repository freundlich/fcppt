//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/dim/has_dim.hpp>
#include <fcppt/math/dim/static.hpp>

int main()
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  static_assert(fcppt::math::dim::has_dim<ui2_dim, 2>::value);
}
