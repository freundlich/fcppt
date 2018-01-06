//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_SET_DIFFERENCE_HPP_INCLUDED
#define FCPPT_BRIGAND_SET_DIFFERENCE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/if.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/has_key.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief The difference of two sets.

\ingroup fcpptbrigand

The result contains every element that is in \a Set1, but not in \a Set2.

\tparam Set1 Must be a brigand set.
\tparam Set2 Must be a brigand set.
*/
template<
	typename Set1,
	typename Set2
>
using set_difference
=
::brigand::fold<
	Set1,
	::brigand::set<>,
	::brigand::if_<
		::brigand::bind<
			::brigand::has_key,
			::brigand::pin<
				Set2
			>,
			::brigand::_element
		>,
		::brigand::_state,
		::brigand::bind<
			::brigand::insert,
			::brigand::_state,
			::brigand::_element
		>
	>
>;

}
}

#endif
