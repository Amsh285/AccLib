
#include <gtest/gtest.h>
#include "../AccLib/String.h"


TEST(StringTests, string_init)
{
    acclib::String sut;
    ASSERT_EQ(0, (int)sut.length());
    ASSERT_EQ(1, (int)sut.size());
}

TEST(StringTests, string_copy_ctor)
{
    acclib::String other("hallo Welt");
    acclib::String sut = other;

    ASSERT_EQ(other[0], sut[0]);
    ASSERT_EQ(other.size(), sut.size());
    ASSERT_EQ(other.length(), sut.length());

    sut.at(0) = '$';

    char s = sut[0];

    ASSERT_EQ('h', other[0]);
    ASSERT_EQ('$', sut[0]);
}

TEST(StringTests, string_move_ctor)
{
	acclib::String pseudo_rvalue("test");
	acclib::String sut = std::move(pseudo_rvalue);

	ASSERT_TRUE(sut == "test");

	const acclib::vector<char>& r_buffer = pseudo_rvalue.buffer();

	ASSERT_EQ(0, (int)r_buffer.capacity());
	ASSERT_EQ(0, (int)r_buffer.size());
	ASSERT_TRUE(r_buffer.buffer() == nullptr);
}

TEST(StringTests, string_copy_assignment)
{
	acclib::String other = "Hoi";
	acclib::String sut;
	sut = other;

	ASSERT_TRUE(other == "Hoi");
	ASSERT_TRUE(sut == "Hoi");

	sut.at(0) = 'B';

	ASSERT_TRUE(other == "Hoi");
	ASSERT_TRUE(sut == "Boi");
}

TEST(StringTests, string_move_assignment)
{
	acclib::String pseudo_rvalue("test");
	acclib::String sut;
	sut	= std::move(pseudo_rvalue);

	ASSERT_TRUE(sut == "test");

	const acclib::vector<char>& r_buffer = pseudo_rvalue.buffer();

	ASSERT_EQ(0, (int)r_buffer.capacity());
	ASSERT_EQ(0, (int)r_buffer.size());
	ASSERT_TRUE(r_buffer.buffer() == nullptr);
}

TEST(StringTests, string_plus_operator)
{
	acclib::String sut = "Hallo ";
	sut = sut + "Welt";

	ASSERT_TRUE(sut == "Hallo Welt");

	sut = "Hallo ";

	ASSERT_TRUE(sut == "Hallo ");

	sut = sut + acclib::String("Welt");

	ASSERT_TRUE(sut == "Hallo Welt");
}

TEST(StringTests, string_plus_assignment_operator)
{
	acclib::String temp = "lt";
	acclib::String sut = "Hallo ";
	sut += "We";

	ASSERT_TRUE(sut == "Hallo We");

	sut += temp;

	ASSERT_TRUE(sut == "Hallo Welt");
}

TEST(StringTests, string_init_with_value)
{
	const char* expected_value = "Hallo Welt";
	acclib::String sut(expected_value);

	ASSERT_EQ((int)strlen(expected_value), (int)sut.length());
	ASSERT_EQ((int)(strlen(expected_value) + 1), (int)sut.size());
	//Equals check
	ASSERT_TRUE(sut == expected_value);
}

TEST(StringTests, string_iterator)
{
	const char* expected = "Hallo";
	int i = 0;
	acclib::String sut(expected);

	for (acclib::String::string_iterator it = sut.begin(); it != sut.end(); ++it)
	{
		ASSERT_EQ(expected[i], *it);
		++i;
	}
}

TEST(StringTests, string_c_str)
{
	acclib::String sut("i love to hate c++");
	const char* str = sut.c_str();

	ASSERT_TRUE(sut == str);
}
