#include <gtest/gtest.h>

#include "../ s21_matrix_oop.h"

using namespace std;

TEST(S21Matrix, EqMatrix1) {
  S21Matrix A(3);
  S21Matrix B(3);
  ASSERT_TRUE(1 == A.EqMatrix(B));
}

TEST(S21Matrix, EqMatrix2) {
  S21Matrix A(3);
  S21Matrix B(3);
  B.set_matrix_number(2, 2, 4.5);
  ASSERT_FALSE(1 == A.EqMatrix(B));
  ASSERT_TRUE(0 == A.EqMatrix(B));
}

TEST(S21Matrix, SumMatrix) {
  S21Matrix A(2);
  A.set_matrix_number(0, 0, 2.3);
  A.set_matrix_number(0, 1, 3.5);
  A.set_matrix_number(1, 0, 4.2);
  A.set_matrix_number(1, 1, 6.8);
  S21Matrix B = A;
  B.SumMatrix(A);
  B.SubMatrix(A);
  B.SubMatrix(A);
  S21Matrix C(2);
  ASSERT_TRUE(1 == C.EqMatrix(B));
}

TEST(S21Matrix, WithoutName1) {
  S21Matrix A;
  EXPECT_ANY_THROW(S21Matrix B(-3, 4));
  S21Matrix C(2);
  S21Matrix D = std::move(C);
  EXPECT_ANY_THROW(C.SumMatrix(A));
  EXPECT_ANY_THROW(C.SubMatrix(A));
}

TEST(S21Matrix, Mult) {
  S21Matrix A(3, 2);
  A.MulNumber(5.6);
  A.set_matrix_number(0, 0, 1);
  A.set_matrix_number(0, 1, 2);
  A.set_matrix_number(1, 0, 3);
  A.set_matrix_number(1, 1, 4);
  A.set_matrix_number(2, 0, 5);
  A.set_matrix_number(2, 1, 6);
  double t = 0;
  EXPECT_ANY_THROW(t = A.Determinant());
  EXPECT_ANY_THROW(S21Matrix U = A.CalcComplements());
  EXPECT_ANY_THROW(S21Matrix U2 = A.CalcComplements());
  ASSERT_TRUE(0 == t);
  S21Matrix B(2, 3);
  B.set_matrix_number(0, 0, 7);
  B.set_matrix_number(0, 1, 8);
  B.set_matrix_number(0, 2, 9);
  B.set_matrix_number(1, 0, 10);
  B.set_matrix_number(1, 1, 11);
  B.set_matrix_number(1, 2, 12);
  A.MulMatrix(B);
  S21Matrix C(5);
  EXPECT_ANY_THROW(C.MulMatrix(B));
  S21Matrix Y = B.Transpose();
}

TEST(S21Matrix, Determinant) {
  S21Matrix C(1);
  C.set_matrix_number(0, 0, 12);
  ASSERT_TRUE(12 == C.Determinant());
  S21Matrix B(2);
  B.set_matrix_number(0, 0, 7);
  B.set_matrix_number(0, 1, 8);
  B.set_matrix_number(1, 0, 9);
  B.set_matrix_number(1, 1, 10);
  ASSERT_TRUE(-2 == B.Determinant());
  S21Matrix A(3);
  A.set_matrix_number(0, 0, 1);
  A.set_matrix_number(0, 1, 2);
  A.set_matrix_number(0, 2, 3);
  A.set_matrix_number(1, 0, 4);
  A.set_matrix_number(1, 1, 5);
  A.set_matrix_number(1, 2, 6);
  A.set_matrix_number(2, 0, 7);
  A.set_matrix_number(2, 1, 8);
  A.set_matrix_number(2, 2, 9);
  ASSERT_TRUE(0 == A.Determinant());
}

TEST(S21Matrix, InverseMatrix) {
  S21Matrix A(3);
  A.set_matrix_number(0, 0, 5);
  A.set_matrix_number(0, 1, 7);
  A.set_matrix_number(0, 2, 1);
  A.set_matrix_number(1, 0, -4);
  A.set_matrix_number(1, 1, 1);
  A.set_matrix_number(1, 2, 0);
  A.set_matrix_number(2, 0, 2);
  A.set_matrix_number(2, 1, 0);
  A.set_matrix_number(2, 2, 3);

  S21Matrix B = A.InverseMatrix();
  S21Matrix v(3);
  v.set_matrix_number(0, 0, 5);
  v.set_matrix_number(0, 1, 6);
  v.set_matrix_number(0, 2, 7);
  v.set_matrix_number(1, 0, 8);
  v.set_matrix_number(1, 1, 9);
  v.set_matrix_number(1, 2, 10);
  v.set_matrix_number(2, 0, 11);
  v.set_matrix_number(2, 1, 12);
  v.set_matrix_number(2, 2, 13);
  EXPECT_ANY_THROW(S21Matrix v2 = v.InverseMatrix());
}
TEST(S21Matrix, operators) {
  S21Matrix A(3);
  A.set_matrix_number(0, 0, 5);
  A.set_matrix_number(0, 1, 7);
  A.set_matrix_number(0, 2, 1);
  A.set_matrix_number(1, 0, -4);
  A.set_matrix_number(1, 1, 1);
  A.set_matrix_number(1, 2, 0);
  A.set_matrix_number(2, 0, 2);
  A.set_matrix_number(2, 1, 0);
  A.set_matrix_number(2, 2, 3);

  S21Matrix B = A.InverseMatrix();
  S21Matrix C(3);
  C.set_matrix_number(0, 0, 5);
  C.set_matrix_number(0, 1, 6);
  C.set_matrix_number(0, 2, 7);
  C.set_matrix_number(1, 0, 8);
  C.set_matrix_number(1, 1, 9);
  C.set_matrix_number(1, 2, 10);
  C.set_matrix_number(2, 0, 11);
  C.set_matrix_number(2, 1, 12);
  C.set_matrix_number(2, 2, 13);
  S21Matrix C0(3);
  S21Matrix C2 = C + C0;
  ASSERT_TRUE(C2 == C);
  S21Matrix C3 = C - C0;
  ASSERT_TRUE(C3 == C);
  C3 -= C0;
  C3 += C0;
  ASSERT_TRUE(C3 == C);
  S21Matrix C4 = C * C0;
  ASSERT_TRUE(C4 == C0);
  C3 *= C4;
  ASSERT_TRUE(C4 == C0);
  double r = C4(2, 2);
  ASSERT_TRUE(r == 0);
  EXPECT_ANY_THROW(r = C4(0, 3));
  C4 *= r;
  S21Matrix C5 = 8 * C4;
  ASSERT_TRUE(C5 == C4);
  C5 = C3;
  ASSERT_TRUE(C5 == C3);
  S21Matrix CLast(7);
  ASSERT_TRUE(0 == C3.EqMatrix(CLast));
}

TEST(S21Matrix, AccesssorsMutators) {
  S21Matrix A(3, 4);
  A.set_matrix_number(0, 0, 5);
  A.set_matrix_number(0, 1, 7);
  A.set_matrix_number(0, 2, 1);
  A.set_matrix_number(1, 0, -4);
  A.set_matrix_number(1, 1, 1);
  A.set_matrix_number(1, 2, 0);
  A.set_matrix_number(2, 0, 2);
  A.set_matrix_number(2, 1, 0);
  A.set_matrix_number(2, 2, 3);
  A.ShowMatrix();
  ASSERT_TRUE(4 == A.GetCols());
  ASSERT_TRUE(3 == A.GetRows());
  A.EditRowsCols(5, 2);
  printf("\n");
  A.ShowMatrix();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}