//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_ACTOR_NORMALIZED_HPP_INCLUDED
#define FCPPT_RANDOM_ACTOR_NORMALIZED_HPP_INCLUDED

#include <fcppt/random/actor/float_type.hpp>
#include <fcppt/random/actor/container.hpp>
#include <fcppt/random/uniform.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace fcppt
{
namespace random
{
namespace actor
{

/// The normalized actor
/**
 * It takes a container of elements and distributes
 * evenly depending on how big each element's probability is.
*/
class normalized
{
	FCPPT_NONCOPYABLE(normalized)
public:
	FCPPT_SYMBOL explicit normalized(
		container const &
	);

	FCPPT_SYMBOL ~normalized();

	/// invoke the random generator
	FCPPT_SYMBOL void
	operator()();
private:
	typedef uniform<
		float_type
	> rng_type;

	container const elements;

	rng_type rng;
};

}
}
}

#endif
