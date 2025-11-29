#include "../../ s21_matrix_oop.h"

double S21Matrix::get_determinant_two_dimensional() {
  return matrix_[0][0] * matrix_[1][1] - (matrix_[0][1] * matrix_[1][0]);
}