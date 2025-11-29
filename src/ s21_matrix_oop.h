#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <math.h>

#include <stdexcept>

#include "stdio.h"

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double **matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  // Constructors
  S21Matrix() noexcept;  // Default constructor
  S21Matrix(int, int);
  S21Matrix(int n) : S21Matrix(n, n){};
  S21Matrix(const S21Matrix &);
  S21Matrix(S21Matrix &&);
  ~S21Matrix();  // Destructor

  // operations
  S21Matrix CalcComplements();
  double Determinant();
  bool EqMatrix(const S21Matrix &);
  S21Matrix InverseMatrix();
  void MulMatrix(const S21Matrix &);
  void MulNumber(const double);
  void SubMatrix(const S21Matrix &);
  void SumMatrix(const S21Matrix &);
  S21Matrix Transpose();

  // operators
  double operator()(int, int);
  friend S21Matrix operator*(S21Matrix &, S21Matrix &);
  friend S21Matrix operator*(S21Matrix &, double);
  friend S21Matrix operator*(double, S21Matrix &);
  friend S21Matrix operator-(S21Matrix &, S21Matrix &);
  S21Matrix operator-=(S21Matrix &);
  S21Matrix operator*=(S21Matrix &);
  S21Matrix operator*=(double);
  friend S21Matrix operator+(S21Matrix &, S21Matrix &);
  S21Matrix operator+=(S21Matrix &);
  S21Matrix operator=(S21Matrix &);
  bool operator==(S21Matrix &);

  // Helper
  void for_determinant(double &, double[100], int);
  double get_determinant_two_dimensional();
  S21Matrix get_minor_matrix(int, int);
  void set_matrix_number(int i, int j, double a) { matrix_[i][j] = a; }

  // Accessors and mutators
  int GetRows() { return rows_; }

  int GetCols() { return cols_; }

  void EditRowsCols(int rows, int cols);
  // Other methods..

  void ShowMatrix() {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        printf("%lf ", matrix_[i][j]);
      }
      printf("\n");
    }
  }
};

#endif