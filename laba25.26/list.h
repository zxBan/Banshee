#ifndef list_h
#define list_h
#include <stdio.h>
#include "stdlib.h"

typedef struct list
{
    int k;
    struct list *next;
} list;
typedef struct list Node;

struct list *create_list(struct list *l, int n);
int empty(struct list *l);
void push(struct list *l, int k);
int find(struct list *l, int n, int r);
struct list *delete( struct list *l, int n);
void output(struct list *l);
int length(struct list *l, int r);
struct list *sort(struct list *l);

#endif