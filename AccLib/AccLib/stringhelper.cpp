#pragma once

#include "stringhelper.h"

namespace acclib
{
    size_t string_length(const char* source)
    {
        if(source == nullptr)
            throw new std::invalid_argument("source cannot be null.");
        
        size_t count;

        for(count = 0; *source; ++count)
            ++source;
        
        return count;
    }

    size_t index_of(const char* source, const char& search_value)
    {
        if(source == nullptr)
            throw new std::invalid_argument("source cannot be null.");

        size_t source_length = string_length(source);

        for (size_t i = 0; i < source_length; ++i)
        {
            if(source[i] == search_value)
                return i;
        }
        
        return acclib::npos;
    }
}