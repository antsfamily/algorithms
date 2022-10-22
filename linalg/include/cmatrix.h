/*
 * @file      : cmatrix.h
 * @author    : Zhi Liu
 * @email     : zhiliu.mind@gmail.com
 * @homepage  : http://iridescent.ink
 * @date      : Sat Oct 22 2022
 * @version   : v0.0
 * @license   : The Apache License 2.0
 * @note      : 
 * 
 * The Apache 2.0 License (MIT)
 * Copyright (C) 2013 Zhi Liu
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */

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

int init(cmatrix *pSrc, int rows, int cols);
void destroy(cmatrix *pSrc);
void set(cmatrix *pSrc, mdtype vreal, mdtype vimag);
void transpose(cmatrix *pSrc, cmatrix *pDst);
void conjugate(cmatrix *pSrc, cmatrix *pDst);
void conjtrans(cmatrix *pSrc, cmatrix *pDst);
void cmabs(cmatrix *pSrc, cmatrix *pDst);
void cmpow(cmatrix *pSrc, cmatrix *pDst, double p);
void cmadd(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst);
void cmsub(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst);
void cmmul(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst);
void cmelemul(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst);
void cmprint(cmatrix A);


