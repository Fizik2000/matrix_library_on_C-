#include "../ s21_matrix_oop.h"

double S21Matrix::Determinant() {
  double result = 0;
  double mult[100];
  if (rows_ != cols_) throw "The matrix is not square\n";
  if (cols_ == 1)
    result = matrix_[0][0];
  else
    this->for_determinant(result, mult, rows_ - 2);

  return result;
}