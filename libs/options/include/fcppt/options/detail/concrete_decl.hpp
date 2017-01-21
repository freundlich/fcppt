//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_CONCRETE_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CONCRETE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/base_decl.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/detail/concrete_fwd.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Result,
	typename Parser
>
class concrete
:
	public
		fcppt::options::base<
			Result
		>
{
	typedef
	fcppt::options::base<
		Result
	>
	base_type;

	FCPPT_NONCOPYABLE(
		concrete
	);
public:
	explicit
	concrete(
		Parser &&
	);

	explicit
	concrete(
		Parser const &
	);

	~concrete()
	override;

	typedef
	Result
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::state &
	) const
	override;

	fcppt::options::has_parameter_set
	parameters() const
	override;

	fcppt::string
	usage() const
	override;
private:
	Parser const parser_;
};

}
}
}

#endif
