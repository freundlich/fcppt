//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED

#include <fcppt/function.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/connection.hpp>


namespace fcppt
{
namespace signal
{
namespace detail
{

template<
	typename T
>
class concrete_connection
:
	public fcppt::signal::connection
{
	FCPPT_NONCOPYABLE(
		concrete_connection
	);
public:
	typedef T function_signature;

	typedef
	fcppt::function<
		T
	>
	function_type;

	explicit
	concrete_connection(
		function_type const &
	);

	~concrete_connection()
	override;

	function_type &
	function();
private:
	function_type function_;
};

}
}
}

#endif
