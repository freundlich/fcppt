//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_ADVANCED_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_ADVANCED_HPP_INCLUDED

#include <fcppt/enum_max_value.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_wrapper.hpp>
#include <fcppt/random/distribution/transform/enum.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace parameters
{

template<
	typename Distribution,
	typename Enum
>
typename
boost::enable_if<
	std::is_enum<
		Enum
	>,
	fcppt::random::distribution::parameters::uniform_int<
		Enum,
		Distribution
	>
>::type const
make_uniform_enum_advanced()
{
	typedef
	fcppt::random::distribution::parameters::uniform_int<
		Enum,
		Distribution
	>
	param_type;

	return
		param_type(
			typename param_type::min(
				fcppt::cast::int_to_enum<
					Enum
				>(
					0u
				)
			),
			typename param_type::max(
				fcppt::enum_max_value<
					Enum
				>::value
			)
		);
}

}
}
}
}

#endif
