#pragma once

#include <turbodbc/field_translator.h>

namespace turbodbc { namespace field_translators {

/**
 * @brief Translates bytes values into buffer elements and vice versa
 */
class bytes_translator : public field_translator {
public:
	bytes_translator();
	~bytes_translator();
private:
	field do_make_field(char const * data_pointer) const final;
};

} }
