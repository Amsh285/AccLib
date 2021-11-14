
#include <gtest/gtest.h>
#include "../AccLib/vector.h"

void test_growth(size_t initialcapacity);

TEST(VectorTests, vector_works_as_intended)
{
	acclib::vector<int> sut;
	sut.push_back(1);
	sut.push_back(2);
	sut.push_back(3);
	sut.push_back(4);

	sut[3] = 5;

	ASSERT_EQ(1, sut[0]);
	ASSERT_EQ(2, sut[1]);
	ASSERT_EQ(3, sut[2]);
	ASSERT_EQ(5, sut[3]);
}

TEST(VectorTests, vector_copy_ctor)
{
	acclib::vector<int> other;
	other.push_back(1);
	other.push_back(2);
	other.push_back(3);

	acclib::vector<int> sut = other;

	sut[0] = 12;
	ASSERT_EQ(1, other[0]);
	ASSERT_EQ(12, sut[0]);
}

TEST(VectorTests, vector_move_ctor)
{
	acclib::vector<int> pseudo_rvalue = acclib::vector<int>(12);
	acclib::vector<int> sut = std::move(pseudo_rvalue);
	sut.push_back(123);

	ASSERT_EQ(0, (int)pseudo_rvalue.capacity());
	ASSERT_EQ(0, (int)pseudo_rvalue.size());
	ASSERT_TRUE(pseudo_rvalue.buffer() == nullptr);
	ASSERT_EQ(123, sut.at(0));
	ASSERT_EQ(1, (int)sut.size());
	ASSERT_EQ(12, (int)sut.capacity());
}

TEST(VectorTests, vector_copy_assignment)
{
	acclib::vector<int> other;
	other.push_back(1);
	other.push_back(2);
	other.push_back(3);

	acclib::vector<int> sut;
	sut = other;
	sut[0] = 100;

	ASSERT_EQ(1, other[0]);
	ASSERT_EQ(100, sut[0]);
}

TEST(VectorTests, vector_move_assignment)
{
	acclib::vector<int> pseudo_rvalue = acclib::vector<int>(12);
	acclib::vector<int> sut = acclib::vector<int>();
	pseudo_rvalue.push_back(123);
	sut = std::move(pseudo_rvalue);

	ASSERT_EQ(0, (int)pseudo_rvalue.capacity());
	ASSERT_EQ(0, (int)pseudo_rvalue.size());
	ASSERT_TRUE(pseudo_rvalue.buffer() == nullptr);
	ASSERT_EQ(123, sut.at(0));
	ASSERT_EQ(1, (int)sut.size());
	ASSERT_EQ(12, (int)sut.capacity());
}

TEST(VectorTests, vector_can_grow)
{
	test_growth(0);
	test_growth(1);
	test_growth(2);
	test_growth(3);
	test_growth(300);
}

TEST(VectorTests, vector_can_shrink)
{
	acclib::vector<int> sut(4);
	sut.push_back(1);
	sut.push_back(2);
	sut.push_back(3);
	sut.push_back(4);
	sut.resize(2);

	ASSERT_EQ(1, sut[0]);
	ASSERT_EQ(2, sut[1]);
	ASSERT_EQ(2, (int)sut.size());
	ASSERT_EQ(2, (int)sut.capacity());
}

TEST(VectorTests, vector_can_write)
{
	acclib::vector<char> sut;
	sut.push_back('a');
	sut.push_back('b');
	sut.push_back('c');
	sut[2] = 'd';

	ASSERT_EQ('d', sut[2]);
}

TEST(VectorTests, vector_iterator)
{
	int expected = 1;
	acclib::vector<int> sut;
	sut.push_back(1);
	sut.push_back(2);
	sut.push_back(3);
	sut.push_back(4);

	for (acclib::vector<int>::iterator<int> it = sut.begin(); it != sut.end(); ++it)
	{
		int actual = *it;
		ASSERT_EQ(expected, actual);
		++expected;
	}
}

TEST(VectorTests, vector_reverse_iterator)
{
	int expected = 5;

	acclib::vector<int> sut;
	sut.push_back(1);
	sut.push_back(2);
	sut.push_back(3);
	sut.push_back(4);
	sut.push_back(5);

	for (acclib::vector<int>::vector_reverse_iterator it = sut.rbegin(); it != sut.rend(); ++it)
	{
		int actual = *it;
		ASSERT_EQ(expected, actual);
		--expected;
	}
}

TEST(VectorTests, vector_std_find)
{
	acclib::vector<int> sut;
	sut.push_back(1);
	sut.push_back(2);
	sut.push_back(3);
	sut.push_back(4);
	sut.push_back(5);

	acclib::vector<int>::iterator<int> it = std::find(sut.begin(), sut.end(), 3);

	ASSERT_EQ(3, *it);
}

void test_growth(size_t initialcapacity)
{
	acclib::vector<int> sut(initialcapacity);

	for (int i = 0; i < 200; ++i)
		sut.push_back(i);

	for (int i = 0; i < 200; ++i)
		ASSERT_EQ((int)i, sut[i]);

	ASSERT_EQ(200, (int)sut.size());
	ASSERT_TRUE(sut.capacity() >= 200);
}