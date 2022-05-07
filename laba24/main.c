#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct StrNode { 
       char data [50]; 
       struct StrNode *left; 
       struct StrNode *right; 
}; 
typedef struct StrNode *node; 

int define_priority (char a) { 
       switch (a){ 
               case '-':  
                       case '+':  
                               return 1; 
               case '*': 
                       return 2; 
               case '/': 
                       return 3; 
               case '^':  
                       return 4; 
               default:  
                       return 100; 
       } 
} 

node MakeTree (char expr[], int first, int last) { 
       int prior, MinPrior = 100, k, depth = 0; 
       node Tree = (node) malloc (sizeof(struct StrNode)); 
       for (int i = first; i <= last; ++i) { 
               if (expr[i] == '(') { 
                       depth++; 
                       continue; 
               } 
               if (expr[i] == ')') { 
                       depth--; 
                       continue; 
               } 
               if (depth>0){ 
                       continue; 
               } 
               prior = define_priority(expr[i]); 
               if (prior <= MinPrior) { 
                       MinPrior = prior; 
                       k = i; 
               } 
       } 
       if (depth !=0) { 
               printf("Wrong expression!\n"); 
               exit (1); 
       } 
       int l; 
       if (MinPrior == 100) { 
               if (expr[first] == '(' && expr[last] == ')') { 
                       free(Tree); 
                       return MakeTree(expr, first +1, last - 1); 
               } 
               else { 
                       l = last - first + 1; 
                       for (int i = 0; i < l; i++ ) { 
                               Tree->data[i] = expr[first+i]; 
                       } 
                       Tree->data[l] = '\n'; 
                       Tree->left = NULL; 
                       Tree->right = NULL; 
                       return Tree; 
               } 
       } 
       Tree->data[0] = expr[k]; 
       Tree->data[1] = '\n'; 
       Tree->left = MakeTree(expr, first, k-1); 
       Tree->right = MakeTree(expr, k+1, last); 
       return Tree; 
} 


void print_tree(node  tr, int l) { 
       if (tr->right != NULL) print_tree(tr->right, l+1); 
       for(int i = 0; i < l; ++i) { 
               printf("   "); 
       } 
       printf("%5s", tr->data); 
       if (tr->left != NULL) print_tree(tr->left, l+1); 

} 


void print_expression(node t) { 
       if (t==NULL) { 
               return; 
       } 
       if (define_priority(t->data[0])!=100 && define_priority(t->left->data[0])!=100 && define_priority(t->data[0])
> define_priority(t->left->data[0])  || t->data[0] == '^' && t->left->data[0] == '^'   ){ 
               printf("("); 
               print_expression(t->left); 
               printf(")"); 
       } else print_expression(t->left); 
       for (int i = 0; i < 50; ++i) { 
               if (t->data[i] == '\n') { 
                       break; 
               } 
               printf("%c", t->data[i]); 
       } 
       if (define_priority(t->data[0])!=100 && define_priority(t->right->data[0])!=100 && define_priority(t->data[0]
) > define_priority(t->right->data[0])  || t->data[0] == '^' && t->right->data[0] == '^'   ){ 
               printf("("); 
               print_expression(t->right); 
               printf(")"); 
       } else print_expression(t->right); 

} 


node copy (node t) { 
       if (t == NULL) { 
               return NULL; 
       } 
       node new_t = (node) malloc (sizeof(struct StrNode)); 
       for (int i = 0; i<50; ++i) { 
               new_t->data[i] = t->data[i]; 
       } 
       new_t ->left = copy(t->left); 
       new_t->right = copy(t->right); 
       return new_t; 
} 



node transformation (node * t) { 
       if (*t == NULL) { 
               return NULL; 
       } 
       if ((*t)->data[0] == '^' && (*t)->right->data[0] == '+') { 
               (*t)->data[0] = '*'; 
               node base1 = copy((*t)->left); 
               node base2 = copy(base1); 
               node degree = copy((*t)->right); 
               char deg [50]; 
               deg[0] = '^'; 
               deg[1] = '\n'; 
               for (int i = 0; i < 50; ++i) { 
                       (*t)->left->data[i] = deg[i]; 
               } 
               (*t)->left->left = base1; 
               (*t)->left->right = (degree)->left; 

               *(*t)->right->data= *deg; 
               (*t)->right->left = base2; 
               (*t)->right->right = (degree)->right; 

       } 
       (*t)->left = transformation(&((*t)->left)); 
       (*t)->right = transformation(&((*t)->right)); 
       return *t; 
} 

int main(void) { 
       node t = NULL; 
       int opt = -1; 
       while (opt!=5) { 
               printf("Choose an action:\n  1. Enter an expression and create tree.\n  2. Transforn expression.\n  3. Print tree.\n  4. Print expression.\n  5. Exit\n"); 
               scanf("%d", &opt); 
               switch (opt) { 
                       case 1: { 
                               printf("Please, enter an expression: "); 
                               char expression[1000]; 
                               scanf("%s", expression); 
                               int n = 0; 
                               while (expression[n] != '\0') { 
                                        n++; 
                               } 
                               t = MakeTree(expression, 0, n-1); 
                               break; 
                       } 
                       case 2: { 
                               t = transformation(&t); 
                               break; 
                       } 
                       case 3: { 
                               printf("\n"); 
                               print_tree(t, 0); 
                               break; 
                       } 
                       case 4: { 
                               printf("\n"); 
                               print_expression(t); 
                               printf("\n"); 
                               break; 
                       } 
               } 
       } 
       return 0; 
}