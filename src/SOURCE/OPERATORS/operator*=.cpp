#include "../../ s21_matrix_oop.h"

S21Matrix S21Matrix::operator*=(S21Matrix& A) {
  this->MulMatrix(A);
  return *this;
}

S21Matrix S21Matrix::operator*=(double a) {
  this->MulNumber(a);
  return *this;
}