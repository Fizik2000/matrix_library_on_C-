#include "../ s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int n, int m) : rows_(n), cols_(m), matrix_(nullptr) {
  matrix_ = nullptr;
  if (rows_ < 0 || cols_ < 0)
    throw "Matrix size must be greater or equal than 0\n";
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_]();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix::S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
}