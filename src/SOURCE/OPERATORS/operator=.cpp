#include "../../ s21_matrix_oop.h"

S21Matrix S21Matrix::operator=(S21Matrix& A) {
  if (matrix_ == A.matrix_) {
  } else {
    this->~S21Matrix();
    rows_ = A.rows_;
    cols_ = A.cols_;
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_]();
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) matrix_[i][j] = A.matrix_[i][j];
    }
  }
  return *this;
}