#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double *buf;
    size_t size;
    size_t capacity;
} vector;

bool v_init(vector *v);
void v_destroy(vector *v);
double v_get(vector *v, size_t i);
void v_set(vector *v, size_t i, double val);
size_t v_get_size(vector *v);
bool v_set_size(vector *v, size_t size);
double v_pop_back(vector *v);
bool v_push_back(vector *v, double val);
void v_swap(vector *v, size_t i1, size_t i2);

#endif