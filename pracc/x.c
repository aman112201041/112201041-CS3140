#include "dataTypes.h"

int main(){

    node* n = createNode('+', 0);
    n->left = createNode('_', 3);

    node* m = createNode('*', 0);
    m->left = createNode('_', 4);
    m->right = createNode('_', 5);

    n->right = m;

    printf("= %d\n", printTree(n));

    return 0;
}

//[1-9][0-9]*     {yylval.num = atoi(yytext); return NUMBER;}