#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

typedef struct {
    int m;
    int n;
    vector k;
    vector v;
} matrix;

void mat_init(matrix *m);
void mat_destroy(matrix *m);
void mat_read(matrix *mat, FILE *f);
void mat_print(matrix *mat);
void mat_print_vec(matrix *mat);
void mat_trans_diag(matrix *mat, matrix *ans);
bool mat_check_skew_symmetry(matrix *mat);

#endif