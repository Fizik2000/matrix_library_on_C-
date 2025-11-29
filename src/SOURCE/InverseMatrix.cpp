#include "../ s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix A(rows_, cols_);
  double det = this->Determinant();
  if (det == 0) throw "Matrix determinant is 0\n";
  S21Matrix B = this->CalcComplements();

  S21Matrix C = B.Transpose();

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) A.matrix_[i][j] = C.matrix_[i][j] / det;
  }
  return A;
}