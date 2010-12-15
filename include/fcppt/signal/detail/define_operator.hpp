//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

#define FCPPT_SIGNAL_DETAIL_DEFINE_EMPTY_OPERATOR\
	result_type operator()() const\
	{\
	}

#define FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR(\
	z,\
	n,\
	_\
)\
template<\
	typename T,\
	template<\
		typename\
	> class Base,\
	typename Enable\
>\
template<\
	BOOST_PP_ENUM_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
typename fcppt::signal::object<\
	T,\
	Base,\
	Enable\
>::result_type \
fcppt::signal::object<\
	T,\
	Base,\
	Enable\
>::operator()(\
	BOOST_PP_ENUM_BINARY_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		T,\
		const &param\
	)\
) const\
{\
	result_type result(\
		this->initial_result_\
	);\
\
	for (\
		typename base::connection_list::iterator it(\
			base::connections().begin()\
		);\
		it != base::connections().end();\
		++it\
	)\
		result = \
			this->combiner_(\
				result,\
				it->function()(\
					BOOST_PP_ENUM_PARAMS_Z(\
						z,\
						BOOST_PP_INC(n),\
						param\
					)\
				)\
			);\
	return result;\
}

#endif
