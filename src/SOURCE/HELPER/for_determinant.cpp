#include "../../ s21_matrix_oop.h"

void S21Matrix::for_determinant(double& sum, double mult[100], int max) {
  for (int i = 0; i < rows_; ++i) {
    if (rows_ == 2) {
      double rt = get_determinant_two_dimensional();
      for (int i = 0; i < max; ++i) rt = rt * mult[i];
      sum += rt;
      i = 2;
    } else {
      for (int w = 0; w < rows_; ++w) {
        if (rows_ == w + 3) {
          mult[w] = matrix_[0][i];
          if (i % 2 == 1) mult[w] = mult[w] * (-1);
        }
      }
      S21Matrix B = this->get_minor_matrix(0, i);
      B.for_determinant(sum, mult, max);
    }
  }
}