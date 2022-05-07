#include <stdio.h> 
#include <stdlib.h>
#include "list.h"

int main() {
    struct list *L = NULL;
    printf("Working with list.Enter Code of command:\n Code a: create list.\n code h: add element\n code f:find element.\n code d: delete element\n code e: check list it is empty\n code p: print list\n code s: sort\n code #:exit\n");
    char op = 'a';
    int e = 1;
    while (op != '#')
    {
        scanf("%c", &op);
        if (op == 'a')
        {
            scanf("%d", &e);
            L = create_list(L, e);
        }
        if (op == 'h')
        {
            scanf("%d", &e);
            push(L, e);
        }
        if (op == 'f')
        {
            scanf("%d", &e);
            int r = find(L, e, 0);
            if (r == 0)
                printf("Not found\n");
            if (r == 1)
                printf("Found 1 element\n");
            if (r > 1)
                printf("Found %d elements\n", r);
        }
        if (op == 'd')
        {
            scanf("%d", &e);
            int r = find(L, e, 0);
            for (int i = 0; i < r; i++)
                L = delete(L, e);
        }
        if (op == 'e')
        {
            if (empty(L) == 0)
                printf("List is empty\n");
            else
                printf("List is not empty\n");
        }
        if (op == 'p')
        {
            output(L);
            printf("\n");
        }
        if (op == 's')
        {
            L = sort(L);
        }
    }
    return 0;
}