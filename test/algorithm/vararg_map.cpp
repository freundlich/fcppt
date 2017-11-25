//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	vararg_map
)
{
	std::tuple<
		unsigned,
		unsigned long
	> const result(
		fcppt::algorithm::vararg_map(
			boost::mpl::vector2<
				int,
				long
			>{},
			[](
				auto const &... _args
			){
				return
					std::make_tuple(
						_args...
					);
			},
			[](
				auto const _tag
			)
			{
				FCPPT_USE(
					_tag
				);

				return
					fcppt::cast::to_unsigned(
						fcppt::literal<
							typename
							std::remove_const<
								decltype(
									_tag
								)
							>::type
						>(
							42
						)
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0u
		>(
			result
		),
		42u
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0u
		>(
			result
		),
		42uL
	);
}

namespace
{

class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	explicit
	movable(
		int const _value
	)
	:
		value_{
			_value
		}
	{
	}

	~movable()
	{
	}

	movable(
		movable &&
	) = default;

	int
	value() const
	{
		return
			value_;
	}
private:
	int value_;
};

}

BOOST_AUTO_TEST_CASE(
	vararg_map_move
)
{
	movable const result{
		fcppt::algorithm::vararg_map(
			std::make_tuple(
				movable{
					42
				}
			),
			[](
				auto && _args
			){
				return
					std::forward<
						decltype(
							_args
						)
					>(
						_args
					);
			},
			[](
				auto &&_arg
			)
			{
				return
					std::forward<
						decltype(
							_arg
						)
					>(
						_arg
					);
			}
		)
	};

	BOOST_CHECK_EQUAL(
		result.value(),
		42
	);
}
