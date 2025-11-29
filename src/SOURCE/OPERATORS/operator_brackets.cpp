#include "../../ s21_matrix_oop.h"

double S21Matrix::operator()(int i, int j) {
  double a = 0;
  if (i > rows_ - 1 || j > cols_ - 1) throw "Index is outside the matrix\n";
  a = matrix_[i][j];

  return a;
}