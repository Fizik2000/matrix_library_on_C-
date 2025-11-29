#include "../ s21_matrix_oop.h"

S21Matrix::~S21Matrix() noexcept {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) delete[] (matrix_[i]);
    delete[] (matrix_);
  }
}