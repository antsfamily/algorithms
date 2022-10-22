
#include <cmatrix.h>
 
/**
 * @brief initilize matrix with malloc
 * 
 * @param A 
 * @param rows 
 * @param cols 
 * @return ** void 
 */
void init(cmatrix *pA, int rows, int cols)
{
    // rows, cols should be larger than 0
    pA->rows = rows;
    pA->cols = cols;
    int size = rows * cols * sizeof(mdtype);
    pA->real = (mdtype*)malloc(size);
    pA->imag = (mdtype*)malloc(size);
}


void destroy(cmatrix *pA)
{
    pA->rows = -1; pA->cols = -1;
    free(pA->real);
    free(pA->imag);
}

/**
 * @brief set all the elements of A to a fix value
 * 
 * @param A the complex matrix pointer
 * @param vreal real part value
 * @param vimag imaginary part value
 */
void set(cmatrix *pA, mdtype vreal, mdtype vimag)
{
	int size = pA->rows * pA->cols;

	for(int i=0; i<size; i++)
	{
		pA->real[i] = vreal;
		pA->imag[i] = vimag;
	}
}

void transpose(cmatrix *pA, cmatrix *pB)
{
    for(int i=0; i<pA->rows; i++)
        for(int j=0; j<pA->cols; j++)
        {
            pB->real[j*pA->cols+i] = pA->real[i*pA->cols+j];
            pB->imag[j*pA->cols+i] = pA->imag[i*pA->cols+j];
        }
}

void conjugate(cmatrix *pA, cmatrix *pB)
{
    for(int i=0; i<pA->rows; i++)
        for(int j=0; j<pA->cols; j++)
        {
            pB->real[i*pA->cols+j] = pA->real[i*pA->cols+j];
            pB->imag[i*pA->cols+j] = -pA->imag[i*pA->cols+j];
        }
}

void conjtrans(cmatrix *pA, cmatrix *pB)
{
    for(int i=0; i<pA->rows; i++)
        for(int j=0; j<pA->cols; j++)
        {
            pB->real[j*pA->cols+i] = pA->real[i*pA->cols+j];
            pB->imag[j*pA->cols+i] = -pA->imag[i*pA->cols+j];
        }
}

void cadd(cmatrix *pA, cmatrix *pB, cmatrix *pC)
{
    int idx=0;

    for(int i=0; i<pA->rows; i++)
    {
        for(int j=0; j<pB->cols; j++)
        {
            idx = i*pA->cols;
            pC->real[idx] = pA->real[idx] + pB->real[idx];
            pC->imag[idx] = pA->imag[idx] + pB->imag[idx];
            idx++;
        }
    }

}

void csub(cmatrix *pA, cmatrix *pB, cmatrix *pC)
{
    int idx=0;

    for(int i=0; i<pA->rows; i++)
    {
        for(int j=0; j<pB->cols; j++)
        {
            idx = i*pA->cols;
            pC->real[idx] = pA->real[idx] - pB->real[idx];
            pC->imag[idx] = pA->imag[idx] - pB->imag[idx];
            idx++;
        }
    }

}

void cmul(cmatrix *pA, cmatrix *pB, cmatrix *pC)
{
    int idxa=0, idxd=0;
    double cr=0, ci=0;
    cmatrix D;

    init(&D, pB->cols, pB->rows);
    transpose(pB, &D);

    for(int i=0; i<pA->rows; i++)
    {
        for(int j=0; j<pB->cols; j++)
        {
            cr = ci = 0.;
            idxa = i*pA->cols; idxd = j*D.cols;
            for(int k=0; k<pA->cols; k++)
            {
                cr += pA->real[idxa] * D.real[idxd] - pA->imag[idxa] * D.imag[idxd];
                ci += pA->real[idxa] * D.imag[idxd] + pA->imag[idxa] * D.real[idxd];
                idxa++; idxd++;
            }
            pC->real[i*pB->cols+j] = cr;
            pC->imag[i*pB->cols+j] = ci;
        }
    }

    destroy(&D);
}

void print_matrix(cmatrix A)
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





