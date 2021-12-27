#include <utility>

#include <gtest/gtest.h>
#include "../AccLib/unique_pointer.h"

TEST(UniquePointerTests, bool_conversionfunc)
{
	acclib::unique_pointer<int> sut(new int(12));

	ASSERT_TRUE(sut);
	sut.reset();
	ASSERT_FALSE(sut);
}

TEST(UniquePointerTests, dereference_operator)
{
	acclib::unique_pointer<int> sut(new int(12));

	ASSERT_TRUE(sut);
	ASSERT_EQ(12, *sut);
}

TEST(UniquePointerTests, move_constructor)
{
	acclib::unique_pointer<int> pseudo_rvalue(new int(12));
	acclib::unique_pointer<int> sut = std::move(pseudo_rvalue);

	ASSERT_TRUE(sut);
	ASSERT_EQ(12, *sut);
	ASSERT_FALSE(pseudo_rvalue);
}

TEST(UniquePointerTests, move_assignment)
{
	acclib::unique_pointer<int> pseudo_rvalue(new int(12));
	acclib::unique_pointer<int> sut;
	sut = std::move(pseudo_rvalue);

	ASSERT_TRUE(sut);
	ASSERT_EQ(12, *sut);
	ASSERT_FALSE(pseudo_rvalue);
}

TEST(UniquePointerTests, swap)
{
	acclib::unique_pointer<int> sut(new int(1));
	acclib::unique_pointer<int> other(new int(2));
	sut.swap(other);

	ASSERT_EQ(2, *sut);
	ASSERT_EQ(1, *other);
}