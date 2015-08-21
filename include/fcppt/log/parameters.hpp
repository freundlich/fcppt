//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/parameters_fwd.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/function_fwd.hpp>
#include <fcppt/log/format/optional_function.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The parameters class for an \link fcppt::log::object \endlink

\ingroup fcpptlog

An object of this class must be used to construct a logger object. A
reasonable default is to call level_streams.
*/
class parameters
{
	FCPPT_NONASSIGNABLE(
		parameters
	);
public:
	/**
	\brief Basic initialization

	Sets enabled to <code>false</code> and the formatter and context
	location to nothing.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	parameters(
		fcppt::log::enabled_level_array const &enabled_levels,
		fcppt::log::level_stream_array const &streams
	);

	/**
	\brief Sets defaults for all levels

	This element function should provide a somewhat often wanted default.

	Sets the enabled status for all levels to true that are equal to or
	higher than \a level. It also sets a level stream for every level using
	\a sink. Uses <code>fcppt::log::enabled_levels(level)</code> and
	<code>fcppt::log::default_level_streams(sink)</code>.

	\param sink The sink to use for every level stream

	\param level The lowest level to activate
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	parameters(
		fcppt::io::ostream &sink,
		fcppt::log::level level
	);


	/**
	\brief Specifies the context and location

	Sets the context and location obtained from \a context_location. This
	is used to insert a logger object in a context at a given location.
	Initially, the context and location are empty.

	\param context_location The context and location to use

	\return <code>*this</code>
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::parameters &
	context_location(
		fcppt::log::context_location const &context_location
	);

	/**
	\brief Specifies the context and location

	Same as
	<code>this->context_location(context_location{context,location})</code>
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::parameters &
	context_location(
		fcppt::log::context &context,
		fcppt::log::location const &location
	);


	/**
	\brief Sets the logger's enabled status

	Sets the enabled status to \a enabled. Initially, enabled is false.

	\param enabled The enabled value to use

	\return <code>*this</code>
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::parameters &
	enabled(
		bool enabled
	);

	/**
	\brief Sets the logger's level stream for a level

	Sets the level stream for \a level to \a stream. Initially, all level
	streams are null pointers.

	\param level The level to change the stream for

	\param stream The new level stream

	\return <code>*this</code>
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::parameters &
	level_stream(
		fcppt::log::level level,
		fcppt::log::level_stream const &stream
	);

	/**
	\brief Activates a log level

	Activates the log level given by \a level. Initially, all levels are
	disabled.

	\param level The level to enable

	\return <code>*this</code>
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::parameters &
	activate(
		fcppt::log::level level
	);

	/**
	\brief Sets the logger's formatter

	Sets the logger's formatter to \a formatter. Initially, the formatter
	is empty.

	\param formatter The formatter to use

	\return <code>*this</code>
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::parameters &
	formatter(
		fcppt::log::format::function const &formatter
	);

	fcppt::log::detail::optional_context_location const &
	context_location() const;

	bool
	enabled() const;

	fcppt::log::level_stream_array const &
	level_streams() const;

	fcppt::log::enabled_level_array const &
	enabled_levels() const;

	fcppt::log::format::optional_function const &
	formatter() const;
private:
	bool enabled_;

	fcppt::log::level_stream_array level_streams_;

	fcppt::log::enabled_level_array enabled_levels_;

	fcppt::log::format::optional_function formatter_;

	fcppt::log::detail::optional_context_location context_location_;
};

}
}

#endif