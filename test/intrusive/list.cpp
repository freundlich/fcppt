//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base.hpp>
#include <fcppt/intrusive/list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

class test_class;

typedef
fcppt::intrusive::list<
	test_class
>
test_list;

class test_class
:
	public
		fcppt::intrusive::base<
			test_class
		>
{
	FCPPT_NONCOPYABLE(
		test_class
	);
public:
	test_class(
		test_list &_list,
		int const _value
	)
	:
		fcppt::intrusive::base<
			test_class
		>{
			_list
		},
		value_{
			_value
		}
	{
	}

	test_class(
		test_class &&
	)
	=
	default;

/*
	test_class &
	operator=(
		test_class &&
	)
	=
	default;*/

	~test_class()
	{
	}

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

TEST_CASE(
	"intrusive::list"
	"[intrusive]"
)
{
	test_list my_list{};

	CHECK(
		std::distance(
			my_list.begin(),
			my_list.end()
		)
		==
		0
	);

	{
		test_class test1{
			my_list,
			42
		};

		CHECK(
			std::distance(
				my_list.begin(),
				my_list.end()
			)
			==
			1
		);

		CHECK(
			std::next(
				my_list.begin()
			)
			==
			my_list.end()
		);

		{
			test_class test2{
				my_list,
				10
			};

			CHECK(
				std::next(
					std::next(
						my_list.begin()
					)
				)
				==
				my_list.end()
			);

			CHECK(
				std::distance(
					my_list.begin(),
					my_list.end()
				)
				==
				2
			);

			CHECK(
				my_list.begin()->value()
				==
				42
			);

			CHECK(
				std::next(
					my_list.begin()
				)->value()
				==
				10
			);

			test_class test3{
				std::move(
					test2
				)
			};

			CHECK(
				std::distance(
					my_list.begin(),
					my_list.end()
				)
				==
				2
			);
		}

		CHECK(
			std::next(
				my_list.begin()
			)
			==
			my_list.end()
		);

		test_list my_list2{
			std::move(
				my_list
			)
		};

		CHECK(
			my_list.empty()
		);

		CHECK(
			std::next(
				my_list2.begin()
			)
			==
			my_list2.end()
		);
	}
}
