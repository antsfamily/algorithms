/*
 * @file      : eigens.c
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

#include <eigens.h>

/**
 * @brief get the eigenvalues and eigenvectors of a complex matrix
 * 
 * @param pA the source cmatrix pointer
 * @param pS the eigenvalues cmatrix pointer
 * @param pV the eigenvectors cmatrix pointer
 * @note 
 * @return
 *       -1 the number of rows or columns of the source is smaller than zero
 *       -2 the number of rows or columns of the eigenvalues is smaller than zero
 *       -3 the number of rows or columns of the eigenvectors is smaller than zero
 *       0 successfully
 */
int cmeig(cmatrix *pA, cmatrix *pS, cmatrix *pV)
{
    int flag = 0;
    // rows, cols should be equal
    if(pA->rows<1 || pA->cols<1)
    {
        flag = -1;
    }
    else if(pS->rows<1 || pS->cols<1)
    {
        flag = -2;
    }
    else if(pV->rows<1 || pV->cols<1)
    {
        flag = -2;
    }

    // TODO

    return flag;

}

