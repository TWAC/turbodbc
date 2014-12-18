/**
 *  @file module.cpp
 *  @date 12.12.2014
 *  @author mkoenig
 *  @brief 
 *
 *  $LastChangedDate$
 *  $LastChangedBy$
 *  $LastChangedRevision$
 *
 */

#include <boost/python/module.hpp>

namespace pydbc { namespace bindings {

	void for_connect();
	void for_connection();
	void for_cursor();

} }

BOOST_PYTHON_MODULE(pydbc)
{
	using namespace pydbc;
	bindings::for_connect();
	bindings::for_connection();
	bindings::for_cursor();
}