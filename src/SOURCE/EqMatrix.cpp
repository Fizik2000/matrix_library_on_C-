#include "../ s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool return_value = 1;
  if (rows_ != other.rows_ || cols_ != other.cols_)
    return_value = 0;
  else
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-07) {
          return_value = 0;
          i = rows_;
          j = cols_;
        }
      }
    }
  return return_value;
}