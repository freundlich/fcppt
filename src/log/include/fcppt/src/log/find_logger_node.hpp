//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_FIND_LOGGER_NODE_HPP_INCLUDED
#define FCPPT_SRC_LOG_FIND_LOGGER_NODE_HPP_INCLUDED

#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/src/log/optional_outer_context_node.hpp>


namespace fcppt
{
namespace log
{

fcppt::log::optional_outer_context_node const
find_logger_node(
	fcppt::log::detail::context_tree &
);

}
}

#endif
