//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/parse/fail.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("parse::fail", "[parse]")
{
  fcppt::parse::fail<fcppt::unit> const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());
}
