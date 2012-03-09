//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_READ_HPP_INCLUDED
#define FCPPT_IO_READ_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/utility/enable_if.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

template<
	typename Type
>
typename boost::enable_if<
	boost::is_fundamental<
		Type
	>,
	fcppt::optional<
		Type
	>
>::type
read(
	std::istream &_stream,
	fcppt::endianness::format::type const _format
)
{
	typedef fcppt::optional<
		Type
	> result_type;

	Type result;

	return
		_stream.read(
			reinterpret_cast<
				char *
			>(
				&result
			),
			sizeof(
				Type
			)
		)
		?
			result_type(
				fcppt::endianness::convert(
					result,
					_format
				)
			)
		:
			result_type()
		;
}

}
}

#endif
