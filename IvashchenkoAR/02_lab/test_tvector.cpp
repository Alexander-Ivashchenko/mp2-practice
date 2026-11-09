#include "tmatrix.h"

#include <gtest/gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);
	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	TDynamicVector<int> v1(v);
	ASSERT_EQ(v, v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	TDynamicVector<int> v1(v);
	v[0] = 5;
	ASSERT_EQ(v1[0], 1);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);
	ASSERT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> v(4);
	v[0] = 4;
	EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(4));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	TDynamicVector<int> v1(v);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int arr1[5] = { 6, 7, 8, 9, 10 };
	TDynamicVector<int> v(arr, 5);
	TDynamicVector<int> v1(arr1, 5);
	ASSERT_NO_THROW(v = v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(3);
	v1 = v;
	ASSERT_EQ(5, v1.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(3);
	ASSERT_NO_THROW(v1 = v);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	TDynamicVector<int> v1(arr, 5);
	ASSERT_TRUE(v == v1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	ASSERT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	TDynamicVector<int> v1(arr, 3);
	ASSERT_TRUE(v != v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int res[5] = { 6, 7, 8, 9, 10 };
	TDynamicVector<int> vres(res, 5);
	ASSERT_EQ(v + 5, vres);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int arr[5] = { 6, 7, 8, 9, 10 };
	TDynamicVector<int> v(arr, 5);
	int res[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> vres(res, 5);
	ASSERT_EQ(v - 5, vres);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int res[5] = { 2, 4, 6, 8, 10 };
	TDynamicVector<int> vres(res, 5);
	ASSERT_EQ(v * 2, vres);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int arr1[5] = { 5, 4, 3, 2, 1 };
	TDynamicVector<int> v1(arr1, 5);
	int res[5] = { 6, 6, 6, 6, 6 };
	TDynamicVector<int> vres(res, 5);
	ASSERT_EQ(v + v1, vres);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int arr1[4] = { 5, 4, 3, 2 };
	TDynamicVector<int> v1(arr1, 4);
	ASSERT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int arr1[5] = { 5, 4, 3, 2, 1 };
	TDynamicVector<int> v1(arr1, 5);
	int res[5] = { -4, -2, 0, 2, 4 };
	TDynamicVector<int> vres(res, 5);
	ASSERT_EQ(v - v1, vres);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int arr1[4] = { 5, 4, 3, 2 };
	TDynamicVector<int> v1(arr1, 4);
	ASSERT_ANY_THROW(v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int arr1[5] = { 5, 4, 3, 2, 1 };
	TDynamicVector<int> v1(arr1, 5);
	int res = 1 * 5 + 2 * 4 + 3 * 3 + 4 * 2 + 5 * 1;
	ASSERT_EQ(v * v1, res);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	TDynamicVector<int> v(arr, 5);
	int arr1[4] = { 5, 4, 3, 2 };
	TDynamicVector<int> v1(arr1, 4);
	ASSERT_ANY_THROW(v * v1);
}

TEST(TDynamicVector, can_move_assign) {
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(5);
	ASSERT_NO_THROW(v1 = std::move(v));
}