//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/expand.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/shrink.hpp>
#include <fcppt/math/box/stretch_absolute.hpp>
#include <fcppt/math/box/stretch_relative.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(box_stretch)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::box::object
	<
		int,
		2
	>
	signed_box_type;

	typedef
	fcppt::math::box::object
	<
		unsigned,
		2
	>
	unsigned_box_type;

	signed_box_type b(
		signed_box_type::vector(10,12),
		signed_box_type::dim(24,26));

	// Expand absolute
	BOOST_CHECK(
		fcppt::math::box::stretch_absolute(
			b,
			signed_box_type::vector(
				2,
				2)
		)
		==
		signed_box_type(
			signed_box_type::vector(
				8,
				10
			),
			signed_box_type::dim(
				28,
				30
			)
		)
	);

	// Shrink absolute
	BOOST_CHECK(
		fcppt::math::box::stretch_absolute(
			b,
			signed_box_type::vector(
				-2,
				-2)
		)
		==
		signed_box_type(
			signed_box_type::vector(
				12,
				14
			),
			signed_box_type::dim(
				20,
				22
			)
		)
	);

	// Expand relative
	BOOST_CHECK(
		fcppt::math::box::stretch_relative(
			b,
			signed_box_type::vector(
				2,
				2)
		)
		==
		signed_box_type(
			signed_box_type::vector(
				-2,
				-1
			),
			signed_box_type::dim(
				48,
				52
			)
		)
	);

	unsigned_box_type ub(
		unsigned_box_type::vector(10u,12u),
		unsigned_box_type::dim(24u,26u));

	// Expand unsigned
	BOOST_CHECK(
		fcppt::math::box::expand(
			ub,
			unsigned_box_type::vector(
				2u,
				2u)
		)
		==
		unsigned_box_type(
			unsigned_box_type::vector(
				8u,
				10u
			),
			unsigned_box_type::dim(
				28u,
				30u
			)
		)
	);

	// Shrink unsigned
	BOOST_CHECK(
		fcppt::math::box::shrink(
			ub,
			unsigned_box_type::vector(
				2u,
				2u)
		)
		==
		unsigned_box_type(
			unsigned_box_type::vector(
				12u,
				14u
			),
			unsigned_box_type::dim(
				20u,
				22u
			)
		)
	);
}
