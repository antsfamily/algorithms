/*
 * @file      : cmatrix.c
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

#include <cmatrix.h>
 

/**
 * @brief initilize matrix with malloc
 * 
 * @param pSrc the cmatrix pointer
 * @param rows the number of rows, > 0
 * @param cols the number of columns, > 0
 * @note 
 * @return
 *       -1 the number of rows or columns is smaller than zero
 *       0 successfully
 */
int init(cmatrix *pSrc, int rows, int cols)
{
    // rows, cols should be larger than 0
    int flag = (rows<1 || cols<1) ? -1:0;
    
    pSrc->rows = rows;
    pSrc->cols = cols;
    int size = rows * cols * sizeof(mdtype);
    pSrc->real = (mdtype*)malloc(size);
    pSrc->imag = (mdtype*)malloc(size);

    return flag;
}

/**
 * @brief destroy a cmatrix
 * 
 * @param pSrc the cmatrix pointer
 */
void destroy(cmatrix *pSrc)
{
    pSrc->rows = -1; pSrc->cols = -1;
    free(pSrc->real);
    free(pSrc->imag);
}

/**
 * @brief set all the elements of A to a fix value
 * 
 * @param A the cmatrix pointer
 * @param vreal real part value
 * @param vimag imaginary part value
 */
void set(cmatrix *pSrc, mdtype vreal, mdtype vimag)
{
	int size = pSrc->rows * pSrc->cols;

	for(int i=0; i<size; i++)
	{
		pSrc->real[i] = vreal;
		pSrc->imag[i] = vimag;
	}
}

/**
 * @brief transpose a complex matrix
 * 
 * @param pSrc the source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void transpose(cmatrix *pSrc, cmatrix *pDst)
{
    int idxA=0, idxB=0;

    for(int i=0; i<pSrc->rows; i++)
    {
        idxA = i*pSrc->cols;
        for(int j=0; j<pSrc->cols; j++)
        {
            idxB = j*pSrc->cols+i;
            pDst->real[idxB] = pSrc->real[idxA];
            pDst->imag[idxB] = pSrc->imag[idxA];
            idxA++;
            idxB++;
        }
    }
}

/**
 * @brief conjugate a complex matrix
 * 
 * @param pSrc the source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void conjugate(cmatrix *pSrc, cmatrix *pDst)
{
    int idx = 0;

    for(int i=0; i<pSrc->rows; i++)
    {
        idx = i*pSrc->cols;
        for(int j=0; j<pSrc->cols; j++)
        {
            pDst->real[idx] = pSrc->real[idx];
            pDst->imag[idx] = -pSrc->imag[idx];
            idx++;
        }
    }
}

/**
 * @brief transpose and conjugate a complex matrix
 * 
 * @param pSrc the source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void conjtrans(cmatrix *pSrc, cmatrix *pDst)
{
    int idxA=0, idxB=0;

    for(int i=0; i<pSrc->rows; i++)
    {
        idxA = i*pSrc->cols;
        for(int j=0; j<pSrc->cols; j++)
        {
            idxB = j*pSrc->cols+i;
            pDst->real[idxB] = pSrc->real[idxA];
            pDst->imag[idxB] = -pSrc->imag[idxA];
            idxA++;
            idxB++;
        }
    }
}

/**
 * @brief addition of two complex matrices
 * 
 * @param pSrc1 the 1st source cmatrix pointer
 * @param pSrc2 the 2nd source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void cmadd(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst)
{
    int idx=0;

    for(int i=0; i<pSrc1->rows; i++)
    {
        idx = i*pSrc1->cols;
        for(int j=0; j<pSrc2->cols; j++)
        {
            pDst->real[idx] = pSrc1->real[idx] + pSrc2->real[idx];
            pDst->imag[idx] = pSrc1->imag[idx] + pSrc2->imag[idx];
            idx++;
        }
    }

}

/**
 * @brief subtraction of two complex matrices
 * 
 * @param pSrc1 the 1st source cmatrix pointer
 * @param pSrc2 the 2nd source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void cmsub(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst)
{
    int idx=0;

    for(int i=0; i<pSrc1->rows; i++)
    {
        idx = i*pSrc1->cols;
        for(int j=0; j<pSrc2->cols; j++)
        {
            pDst->real[idx] = pSrc1->real[idx] - pSrc2->real[idx];
            pDst->imag[idx] = pSrc1->imag[idx] - pSrc2->imag[idx];
            idx++;
        }
    }

}

/**
 * @brief element-by-element multiplication of two complex matrices
 * 
 * @param pSrc1 the 1st source cmatrix pointer
 * @param pSrc2 the 2nd source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void cmelemul(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst)
{
    int idx=0;

    for(int i=0; i<pSrc1->rows; i++)
    {
        idx = i*pSrc1->cols;
        for(int j=0; j<pSrc2->cols; j++)
        {
            pDst->real[idx] = pSrc1->real[idx] * pSrc2->real[idx] - pSrc1->imag[idx] * pSrc2->imag[idx];
            pDst->imag[idx] = pSrc1->real[idx] * pSrc2->imag[idx] + pSrc1->imag[idx] * pSrc2->real[idx];
            idx++;
        }
    }

}

/**
 * @brief absolution a complex matrix
 * 
 * @param pSrc the source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void cmabs(cmatrix *pSrc, cmatrix *pDst)
{
    int idx=0;

    for(int i=0; i<pSrc->rows; i++)
    {
        idx = i*pSrc->cols;
        for(int j=0; j<pDst->cols; j++)
        {
            pDst->real[idx] = sqrt(pSrc->real[idx]*pSrc->real[idx] + pSrc->imag[idx]*pSrc->imag[idx]);
            pDst->imag[idx] = 0.0;
            idx++;
        }
    }
}

/**
 * @brief power (element-by-element) of a complex matrix
 * 
 * @param pSrc the source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void cmpow(cmatrix *pSrc, cmatrix *pDst, double p)
{
    int idx=0;

    for(int i=0; i<pSrc->rows; i++)
    {
        idx = i*pSrc->cols;
        for(int j=0; j<pDst->cols; j++)
        {
            pDst->real[idx] = pow(sqrt(pSrc->real[idx]*pSrc->real[idx] + pSrc->imag[idx]*pSrc->imag[idx]), p);
            pDst->imag[idx] = 0.0;
            idx++;
        }
    }
}

/**
 * @brief complex matrix multiplication
 * 
 * @param pSrc1 the 1st source cmatrix pointer
 * @param pSrc2 the 2nd source cmatrix pointer
 * @param pDst the destination cmatrix pointer
 */
void cmmul(cmatrix *pSrc1, cmatrix *pSrc2, cmatrix *pDst)
{
    int idxa=0, idxd=0;
    double cr=0, ci=0;
    cmatrix D;

    init(&D, pSrc2->cols, pSrc2->rows);
    transpose(pSrc2, &D);

    for(int i=0; i<pSrc1->rows; i++)
    {
        for(int j=0; j<pSrc2->cols; j++)
        {
            cr = ci = 0.;
            idxa = i*pSrc1->cols; idxd = j*D.cols;
            for(int k=0; k<pSrc1->cols; k++)
            {
                cr += pSrc1->real[idxa] * D.real[idxd] - pSrc1->imag[idxa] * D.imag[idxd];
                ci += pSrc1->real[idxa] * D.imag[idxd] + pSrc1->imag[idxa] * D.real[idxd];
                idxa++; idxd++;
            }
            pDst->real[i*pSrc2->cols+j] = cr;
            pDst->imag[i*pSrc2->cols+j] = ci;
        }
    }

    destroy(&D);
}

/**
 * @brief print the elements of a cmatrix
 * 
 * @param A the source cmatrix pointer
 */
void cmprint(cmatrix A)
{
    for(int i=0; i<A.rows; i++)
    {
        for(int j=0; j<A.cols; j++)
        {
            printf("%10.4f + %10.4fj, ", A.real[i*A.cols+j], A.imag[i*A.cols+j]);
        }
        printf("\n");
    }
    printf("\n");
}





