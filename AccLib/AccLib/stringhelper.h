
#include <stdexcept>

namespace acclib
{
    static const size_t npos = -1;

    size_t string_length(const char* source);

    size_t index_of(const char* source, const char& search_value);
}