#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct list *create_list(struct list *l, int n) {
    if (l == NULL) 
    {
        struct list *l = malloc(sizeof(struct list));
        l->k = n;
        l->next = NULL;
        return l;
    }
    l->next = create_list(l->next, n);
}

void push(struct list *l, int k) {
    struct list *current = l;
    while (current->next != NULL) {
    	current = current->next;
    }
    current->next = malloc(sizeof(struct list));
    current->next->k = k;
    current->next->next = NULL;
}	

int empty(struct list *l) {
     if (l == NULL)
        return 0;
    else
        return 1;
}

struct list *delete(struct list *l, int n)
{
    if (l->k == n)
        return l->next;
    if (l == NULL)
        return l;
    if ((l->next)->k == n)
    {
        l->next = (l->next)->next;
        return l;
    }
    delete(l->next, n);
    return l;
}

void output(struct list *l)
{
    if (l == NULL)
        return;
    printf("%d ", l->k);
    output(l->next);
}

int find(struct list *l, int n, int r)
{
    if (l == NULL)
        return r;
    if (l->k == n)
        r++;
    find(l->next, n, r);
}

int length(struct list *l, int r) 
{
    if (l == NULL)
        return r;
    r++;
    length(l->next, r);
}

struct list* sort(struct list* head){
    if(head == NULL || head->next ==NULL)
        return head;
    Node* SortList = (Node*)malloc(sizeof(Node));
    SortList->next = head;
    head = head->next;
    SortList->next->next = NULL;
 
    // Остальные узлы вставлены
    Node* cur = head;
 
    while(cur)
    {
        Node* next = cur->next;
                 // Начиная с заголовка отсортированного списка, находим подходящую позицию для вставляемого узла
        Node* sortprev = SortList;
        Node* sorttail = SortList->next;
 
        while(sorttail)
        {
            if(cur->k > sorttail->k)
            {
                sortprev = sorttail;
                sorttail = sorttail->next;
            }
            else
            {
                break;
            }
        } 
                 // Вставляем в нужное место
        sortprev->next = cur;
        cur->next = sorttail;
 
        cur = next;
    }
    Node* list = SortList->next;
    free(SortList);
 
    return list;
}