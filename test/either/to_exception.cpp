//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <exception>
#include <stdexcept>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("either::to_exception", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  auto const make_exception(
      [](std::string const &_error) { return std::runtime_error{_error}; });

  CHECK(fcppt::either::to_exception(either_int{3}, make_exception) == 3);

  CHECK_THROWS_MATCHES(
      fcppt::either::to_exception(either_int{std::string{"Invalid"}}, make_exception),
      std::exception,
      Catch::Matchers::Predicate< // NOLINT(fuchsia-default-arguments-calls)
          std::exception>([](std::exception const &_exn)
                          { return _exn.what() == std::string{"Invalid"}; }));
}
