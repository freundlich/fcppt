//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/from_list.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same_v<
			fcppt::record::object<
				int,
				float
			>,
			fcppt::record::from_list<
				metal::list<
					int,
					float
				>
			>
		>
	);
}