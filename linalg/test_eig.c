/*
 * @file      : test_eig.c
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

#include <time.h>
#include <eigens.h>

int main()
{

    mdtype Ar[3][3] = {{0.8, -0.6, 0.0}, {0.6, 0.8, 0.0}, {1.0, 2.0, 2.0}};
    mdtype Ai[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    cmatrix A, B, C, S, V;

    Ai[1][1] = 0.5;

    init(&B, 3, 3);
    init(&C, 3, 3);
    init(&S, 3, 1);
    init(&V, 3, 3);
    set(&B, 1.0, 2.0);
    set(&S, 0.0, 0.0);
    set(&V, 0.0, 0.0);
    cmprint(B);

    A.rows = 3; A.cols = 3; A.real = (mdtype *) Ar; A.imag = (mdtype *) Ai;
    
    printf("---origninal\n");
    cmprint(A);

    transpose(&A, &B);
    printf("---transpose\n");
    cmprint(B);

    conjugate(&A, &B);
    printf("---conjugate\n");
    cmprint(B);

    cmabs(&A, &B);
    printf("---complex abs\n");
    cmprint(B);

    cmpow(&A, &B, 2);
    printf("---complex pow\n");
    cmprint(B);

    printf("---summation\n");
    cmadd(&A, &B, &C);
    printf("---A\n");
    cmprint(A);
    printf("---C\n");
    cmprint(C);

    printf("---substract\n");
    cmsub(&A, &B, &C);
    printf("---A\n");
    cmprint(A);
    printf("---C\n");
    cmprint(C);

    printf("---element-by-element multiplication \n");
    cmelemul(&A, &B, &C);
    printf("---A\n");
    cmprint(A);
    printf("---C\n");
    cmprint(C);

    printf("---multiplication\n");
    cmmul(&A, &A, &C);
    printf("---A\n");
    cmprint(A);
    printf("---B\n");
    cmprint(B);
    printf("---C\n");
    cmprint(C);

    printf("---eigen decomposition\n");
    cmeig(&A, &S, &V);
    printf("---A\n");
    cmprint(A);
    printf("---S\n");
    cmprint(S);
    printf("---V\n");
    cmprint(V);

    // printf("Please input one number");
    // scanf("%f", &A.real[0]);

    return 0;
}
