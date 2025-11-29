#include "../../ s21_matrix_oop.h"

S21Matrix S21Matrix::get_minor_matrix(int l, int k) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, i2 = 0; i < rows_; ++i) {
    for (int j = 0, j2 = 0; j < cols_; ++j) {
      if (j != k) {
        if (i != l) result.matrix_[i2][j2] = matrix_[i][j];
        ++j2;
      }
    }
    if (i != l) ++i2;
  }
  return result;
}