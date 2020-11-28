//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::vector::to_signed", "[math],[vector]")
{
  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  using i2_vector = fcppt::math::vector::static_<int, 2>;

  CHECK(fcppt::math::vector::to_signed(ui2_vector{1U, 2U}) == i2_vector(1, 2));
}
