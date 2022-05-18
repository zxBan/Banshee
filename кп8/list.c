#include "list.h"

void add_unit_to_start(unit *u, unit *start){
        u->next = start->next;
        u->prev = start;
        start -> next -> prev = u;
        start -> next = u;
}


list * create_list() {
    list *l = malloc(sizeof(list));
    l->border = malloc(sizeof(unit));
    strcpy(l->border->value, "");
    l->border->next = NULL;
    l->border->prev = NULL;
    return l;
}

void add_list(list *l, char *value) {
    unit *u = malloc(sizeof(unit));
    strcpy(u->value, value);
    if(l->border->prev == NULL) {
        l->border->next = u;
        l->border->prev = u;
        u->next = l->border;
        u->prev = l->border;
        
    }
    else add_unit_to_start(u, l->border->prev);
}

void delete_list(list *l, char *value) {
    unit *curent = l->border->next;
    while(curent != l->border) {
        if(!strcmp(curent->value, value)){
            curent->prev->next = curent->next;
            curent->next->prev = curent->prev;
            curent->next = NULL;
            curent->prev = NULL;
            free(curent);
            break;
        }
        else {
            curent = curent->next;
        }
    }
}

int len_list(list *l) {
    int count = 0;
    unit *curent = l->border->next;
    while (curent != l->border) {
        count++;
        curent = curent->next;
    }
    return count;
}


void print_list(list *l) {
    unit *curent = l->border->next;
    while (curent != l->border) {
        printf("%s ", curent->value);
        curent = curent->next;
    }
    printf("\n");
}

void listprintr(list *l)
{
  struct unit *p = l->border->next;
  while (p != l->border)
    p = p->next;  // переход к концу списка
  do {
    printf("%s ", p->value); // вывод значения элемента p
    p = p->prev; // переход к предыдущему узлу
  } while (p != l->border); // условие окончания обхода
}
