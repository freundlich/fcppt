//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[alignment_simple
#include <fcppt/alignment/align.hpp>
#include <fcppt/alignment/is_aligned.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <ostream>

int main()
{
	int FCPPT_ALIGNMENT_ALIGN(16) test = 0;

	fcppt::io::cout
		<< std::boolalpha
		<< fcppt::alignment::is_aligned(
			&test,
			16
		)
		<< FCPPT_TEXT('\n');
}
//]
