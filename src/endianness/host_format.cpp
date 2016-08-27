//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/private_config.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/endianness/host_format.hpp>


fcppt::endianness::format
fcppt::endianness::host_format()
{
#if defined(FCPPT_IS_BIG_ENDIAN)
	return
		fcppt::endianness::format::big;
#else
	return
		fcppt::endianness::format::little;
#endif
}
