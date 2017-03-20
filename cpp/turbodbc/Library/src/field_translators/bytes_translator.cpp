#include <turbodbc/field_translators/bytes_translator.h>

#include <boost/variant/get.hpp>

#include <stdexcept>

namespace turbodbc { namespace field_translators {

bytes_translator::bytes_translator() = default;

bytes_translator::~bytes_translator() = default;

field bytes_translator::do_make_field(char const * data_pointer) const
{
	return {std::string(data_pointer)};
}


} }
