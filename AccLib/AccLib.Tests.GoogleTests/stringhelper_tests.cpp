#include <gtest/gtest.h>
#include "../AccLib/stringhelper.h"

TEST(StringHelperTests, string_length)
{
    const char* sut = "Hallo";
    size_t actual = acclib::string_length(sut);

    ASSERT_EQ(5, actual);
}

TEST(StringHelperTests, string_length_empty)
{
    size_t actual = acclib::string_length("");

    ASSERT_EQ(0, actual);
}
