#include "../../ s21_matrix_oop.h"

S21Matrix S21Matrix::operator-=(S21Matrix& A) {
  this->SubMatrix(A);
  return *this;
}