#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double mdtype;

/**
 * @brief structure of complex matrix
 * 
 * rows : integer
 * cols : integer
 * *real : real part
 * *imag : imaginary part
 * 
 */
typedef struct{
    int rows;
    int cols;
    mdtype *real;
    mdtype *imag;
}cmatrix;

void init(cmatrix *pA, int rows, int cols);
void destroy(cmatrix *pA);
void set(cmatrix *pA, mdtype vreal, mdtype vimag);
void transpose(cmatrix *pA, cmatrix *pB);
void conjugate(cmatrix *pA, cmatrix *pB);
void conjtrans(cmatrix *pA, cmatrix *pB);
void cadd(cmatrix *pA, cmatrix *pB, cmatrix *pC);
void csub(cmatrix *pA, cmatrix *pB, cmatrix *pC);
void cmul(cmatrix *pA, cmatrix *pB, cmatrix *pC);
// void cabs(cmatrix *pA, cmatrix *pB, cmatrix *pC);
// void cpow(cmatrix *pA, cmatrix *pB, cmatrix *pC);
void print_matrix(cmatrix A);


