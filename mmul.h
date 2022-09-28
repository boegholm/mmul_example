#ifndef C_MATMULT_H
#define C_MATMULT_H

#define MATSIZE (80)
#define MATSIZESQ (MATSIZE*MATSIZE)

void InitArray(double *arr, int size);
double FlatArray(int LoopIterations);
double SFlatArray(int LoopIterations);

#endif //C_MATMULT_H
