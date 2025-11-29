#include "../../ s21_matrix_oop.h"

S21Matrix operator-(S21Matrix& A, S21Matrix& B) {
  S21Matrix result = A;
  result.SubMatrix(B);
  return result;
}