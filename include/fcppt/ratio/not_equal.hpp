//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_NOT_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_NOT_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/not_equal.hpp>
#include <fcppt/ratio/equal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct not_equal
:
boost::mpl::not_<
	equal<
		R1,
		R2
	>
>
{};

}
}

#endif
