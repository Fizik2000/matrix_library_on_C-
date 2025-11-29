#include "../ s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);
  if (rows_ != cols_)
    throw "The matrix is not square";
  else {
    for (int i = 0; i < result.rows_; ++i) {
      for (int j = 0; j < result.cols_; ++j) {
        S21Matrix B = this->get_minor_matrix(i, j);
        int k = (i + j + 2) % 2 == 1 ? -1 : 1;
        double sum = B.Determinant();
        result.matrix_[i][j] = sum * k;
      }
    }
  }
  return result;
}