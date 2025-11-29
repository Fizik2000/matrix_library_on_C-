#include "../ s21_matrix_oop.h"

void S21Matrix::EditRowsCols(int rows, int cols) {
  S21Matrix A(rows, cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (j >= cols_ || i >= rows_) {
      } else
        A.matrix_[i][j] = matrix_[i][j];
    }
  }
  A.ShowMatrix();
  *this = A;
}