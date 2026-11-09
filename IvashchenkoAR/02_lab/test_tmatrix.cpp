#include "tmatrix.h"

#include <gtest\gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);

	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			m[i][j - i] = i * 3 + j;
	TDynamicMatrix<int> m1(m);

	std::cout << "Matrix m:" << endl;
	std::cout << m << endl;

	std::cout << "Matrix m1:" << endl;
	std::cout << m1 << endl;

	ASSERT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			m[i][j - i] = i * 3 + j;
	TDynamicMatrix<int> m1(m);

	m[0][0] = 5;

	ASSERT_NE(m1, m);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(3);
	ASSERT_NO_THROW(m.size());
	EXPECT_EQ(m.size(), 3);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(3);
	m.at(0).at(0) = 1;
	EXPECT_EQ(m.at(0).at(0), 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(3);

	ASSERT_ANY_THROW(m.at(-1).at(-1) = 0);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(3);

	ASSERT_ANY_THROW(m.at(5).at(5) = 0);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(3);

	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);

	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);

	m = m1;

	ASSERT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);

	ASSERT_NO_THROW(m = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			m[i][j - i] = i * 3 + j, m1[i][j - i] = i * 3 + j;

	ASSERT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(3);

	ASSERT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);

	ASSERT_NE(m, m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> res(3);
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			m[i][j - i] = i * 3 + j, m1[i][j - i] = (2 - i) * 3 + (2 - j);
			res[i][j - i] = (i * 3 + j) + ((2 - i) * 3 + (2 - j));
		}
	}

	std::cout << "Matrix m:" << endl;
	std::cout << m << endl;

	std::cout << "Matrix m1:" << endl;
	std::cout << m1 << endl;

	std::cout << "Matrix m + m1:" << endl;
	std::cout << m + m1 << endl;

	std::cout << "Expected:" << endl;
	std::cout << res << endl;

	ASSERT_EQ(m + m1, res);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);

	ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> res(3);
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			m[i][j - i] = i * 3 + j, m1[i][j - i] = i * 3 + j;
			res[i][j - i] = (i * 3 + j) - (i * 3 + j);
		}
	}

	std::cout << "Matrix m:" << endl;
	std::cout << m << endl;

	std::cout << "Matrix m1:" << endl;
	std::cout << m1 << endl;

	std::cout << "Matrix m - m1:" << endl;
	std::cout << m - m1 << endl;

	std::cout << "Expected:" << endl;
	std::cout << res << endl;

	ASSERT_EQ(m - m1, res);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);

	ASSERT_ANY_THROW(m - m1);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size) {
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> res(3);
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			m[i][j - i] = 1, m1[i][j - i] = 1;
			res[i][j - i] = j - i + 1;
		}
	}

	std::cout << "Matrix m:" << endl;
	std::cout << m << endl;

	std::cout << "Matrix m1:" << endl;
	std::cout << m1 << endl;

	std::cout << "Matrix m * m1:" << endl;
	std::cout << m * m1 << endl;

	std::cout << "Expected:" << endl;
	std::cout << res << endl;

	ASSERT_EQ(m * m1, res);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size) {
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);

	ASSERT_ANY_THROW(m * m1);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector_of_matching_size) {
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> x(3);
	TDynamicVector<int> res(3);
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			m[i][j - i] = 1;
		}
		res[i] = 3 - i;
		x[i] = 1;
	}

	std::cout << "Matrix m:" << endl;
	std::cout << m << endl;

	std::cout << "Vector x:" << endl;
	std::cout << x << endl;

	std::cout << "Vector m * x:" << endl;
	std::cout << m * x << endl;

	std::cout << "Expected:" << endl;
	std::cout << res << endl;

	ASSERT_EQ(m * x, res);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_vector_of_nonmatching_size) {
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> x(5);

	ASSERT_ANY_THROW(m * x);
}