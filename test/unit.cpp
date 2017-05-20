//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	unit
)
{
FCPPT_PP_POP_WARNING

	static_assert(
		sizeof(
			fcppt::unit
		)
		==
		1u,
		""
	);

	BOOST_CHECK_EQUAL(
		fcppt::unit{},
		fcppt::unit{}
	);

	BOOST_CHECK(
		!(
			fcppt::unit{}
			!=
			fcppt::unit{}
		)
	);
}
