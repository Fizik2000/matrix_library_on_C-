#include "../../ s21_matrix_oop.h"

S21Matrix operator*(S21Matrix& A, S21Matrix& B) {
  S21Matrix result = A;
  result.MulMatrix(B);
  return result;
}

S21Matrix operator*(S21Matrix& A, double a) {
  S21Matrix result = A;
  result.MulNumber(a);
  return result;
}

S21Matrix operator*(double a, S21Matrix& A) { return A * a; }