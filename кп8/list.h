#ifndef list_h
#define list_h

#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define MAXLEN 256

typedef struct unit {
    char value[MAXLEN];
    struct unit *next;
    struct unit *prev;
}unit;

typedef struct list {
    struct unit *border;
}list;

list * create_list();
void add_list(list *l, char *value);
void delete_list(list *l, char *value);
int len_list(list *l);
void print_list(list *l);
void listprintr(list *l);
void add_unit_to_start(unit *u, unit *start);


#endif