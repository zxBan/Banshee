#include <stdlib.h>
#include <stdbool.h>

const size_t MIN_CAP = 64;

typedef struct{
    double *buf;
    size_t size;
    size_t capacity;
} vector;

bool v_init(vector *v) {
    double *newbuf = malloc(MIN_CAP * sizeof(double));
    if (newbuf != NULL) {
        v->buf = newbuf;
        v->size = 0;
        v->capacity = MIN_CAP;
        return true;
    }
    return false;
}

void v_destroy(vector *v) {
    free(v->buf);
    v->buf = NULL;
    v->size = 0;
    v->capacity = 0;
}

double v_get(vector *v, size_t i) {
    return v->buf[i];
}

void v_set(vector *v, size_t i, double val) {
    v->buf[i] = val;
}

size_t v_get_size(vector *v) {
    return v->size;
}

bool v_set_size(vector *v, size_t new_size) {
    if (new_size > v->capacity) {
        size_t new_cap = v->capacity * 3 / 2;
        if (new_cap < new_size) {
            new_cap = new_size;
        }
        if (new_cap < MIN_CAP) {
            new_cap = MIN_CAP;
        }

        double *new_buf = realloc(v->buf, new_cap * sizeof(double));
        if (new_buf == NULL) {
            return false;
        }

        v->buf = new_buf;
        v->capacity = new_cap;
    }
    else if (new_size * 3 / 2 < v->capacity) {
        size_t new_cap = new_size * 3 / 2;
        if (new_cap < MIN_CAP) {
            new_cap = MIN_CAP;
        }

        v->buf = realloc(v->buf, new_cap * sizeof(double));
        v->capacity = new_cap;
    }

    for (size_t i = v->size; i < new_size; i++) {
        v_set(v, i, 0);
    }

    v->size = new_size;
    return true;
}

double v_pop_back(vector *v) {
    double res = v_get(v, v_get_size(v) - 1);
    v_set_size(v, v_get_size(v) - 1);
    return res;
}

bool v_push_back(vector *v, double val) {
    if (v_set_size(v, v_get_size(v) + 1)) {
        v_set(v, v_get_size(v) - 1, val);
        return true;
    }
    return false;
}

void v_swap(vector *v, size_t i1, size_t i2) {
    double t = v_get(v, i1);
    v_set(v, i1, v_get(v, i2));
    v_set(v, i2, t);
}