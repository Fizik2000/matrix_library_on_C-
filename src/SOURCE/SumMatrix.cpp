#include "../ s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw "different matrix dimensions\n";
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j)
      matrix_[i][j] = other.matrix_[i][j] + matrix_[i][j];
  }
}