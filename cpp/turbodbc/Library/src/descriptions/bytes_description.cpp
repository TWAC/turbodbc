#include <turbodbc/descriptions/bytes_description.h>

#include <boost/variant/get.hpp>

#include <sqlext.h>
#include <cstring>

namespace turbodbc {

bytes_description::bytes_description(std::size_t maximum_length) :
	maximum_length_(maximum_length)
{
}

bytes_description::bytes_description(std::string name, bool supports_null, std::size_t maximum_length) :
	description(std::move(name), supports_null),
	maximum_length_(maximum_length)
{
}

bytes_description::~bytes_description() = default;

std::size_t bytes_description::do_element_size() const
{
	return maximum_length_ + 1;
}

SQLSMALLINT bytes_description::do_column_c_type() const
{
	return SQL_C_BINARY;
}

SQLSMALLINT bytes_description::do_column_sql_type() const
{
	return SQL_VARBINARY;
}

SQLSMALLINT bytes_description::do_digits() const
{
	return 0;
}

type_code bytes_description::do_get_type_code() const
{
	return type_code::bytes;
}

}
