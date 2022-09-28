#include <stdlib.h>
#include "mmul.h"

void InitArray(double *arr, const int size){
    for(int i = 0; i < size; i++){
        int offset = i * size;
        for(int j = 0; j < size; j++){
            arr[offset + j] = i + j;
        }
    }
}



double SFlatArray(int LoopIterations){
    double d;
    double Aa[MATSIZESQ];
    double Ba[MATSIZESQ];
    double Ra[MATSIZESQ];
    double *A = Aa;
    double *B = Ba;
    double *R = Ra;
    InitArray(A, MATSIZE);
    InitArray(B, MATSIZE);
    for(int i = 0; i < LoopIterations; i++) {
        for (int r = 0; r < MATSIZE; r++) {
            for (int c = 0; c < MATSIZE; c++) {
                double sum = 0.0;
                for (int k = 0; k < MATSIZE; k++) {
                    sum += A[r * MATSIZE + k] * B[k * MATSIZE + c];
                }
                *(R + r * MATSIZE + c) = sum;
            }
        }
    }
    d=*R;
    return d;
}
/***
 * Benchmark for Matrix multiplication
 */
double FlatArray(int LoopIterations){
    double d;
    double *A = (double*) calloc(MATSIZESQ, sizeof(double));
    double *B = (double*) calloc(MATSIZESQ, sizeof(double));
    double* R = (double*) calloc(MATSIZESQ, sizeof(double));
    InitArray(A, MATSIZE);
    InitArray(B, MATSIZE);
    for(int i = 0; i < LoopIterations; i++) {
        for (int r = 0; r < MATSIZE; r++) {
            for (int c = 0; c < MATSIZE; c++) {
                double sum = 0.0;
                for (int k = 0; k < MATSIZE; k++) {
                    sum += A[r * MATSIZE + k] * B[k * MATSIZE + c];
                }
                *(R + r * MATSIZE + c) = sum;
            }
        }
    }
    d=*R;
    free(A);
    free(B);
    free(R);
    return d;
}
