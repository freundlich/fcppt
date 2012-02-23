//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_FIND_INNER_NODE_HPP_INCLUDED
#define FCPPT_SRC_LOG_FIND_INNER_NODE_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/variant/object_decl.hpp>


namespace fcppt
{
namespace log
{

fcppt::log::detail::context_tree::iterator
find_inner_node(
	fcppt::log::detail::context_tree &,
	fcppt::string const &name
);

}
}

#endif