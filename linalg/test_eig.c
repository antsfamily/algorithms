


#include <time.h>
#include <cmatrix.h>

int main()
{

    mdtype Ar[3][3] = {{0.8, -0.6, 0.0}, {0.6, 0.8, 0.0}, {1.0, 2.0, 2.0}};
    mdtype Ai[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    cmatrix A, B, C;

    Ai[1][1] = 0.5;

    init(&B, 3, 3);
    init(&C, 3, 3);
    set(&B, 1.0, 2.0);
    print_matrix(B);

    A.rows = 3; A.cols = 3; A.real = (mdtype *) Ar; A.imag = (mdtype *) Ai;
    
    printf("---origninal\n");
    print_matrix(A);

    transpose(&A, &B);
    printf("---transpose\n");
    print_matrix(B);

    conjugate(&A, &B);
    printf("---conjugate\n");
    print_matrix(B);

    printf("---multiplication\n");
    cmul(&A, &B, &C);
    printf("---A\n");
    print_matrix(A);
    printf("---B\n");
    print_matrix(B);
    printf("---C\n");
    print_matrix(C);

    return 0;
}




