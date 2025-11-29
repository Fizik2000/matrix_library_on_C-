#include "../ s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw "The number of columns of the first matrix is not equal to the number of rows of the second matrix\n";
  S21Matrix A = std::move(*this);
  cols_ = other.cols_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_]();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 0;
      int k = 0;
      while (k < A.cols_) {
        matrix_[i][j] += A.matrix_[i][k] * other.matrix_[k][j];
        ++k;
      }
    }
  }
}