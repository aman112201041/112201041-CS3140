#ifndef DATA_TYPES_
#define DATA_TYPES_

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    char op;
    int val;
} node;

node* createNode(char op, int val, node* left, node* right){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->left = left;
    newNode->right = right;
    newNode->op = op;
    newNode->val = val;

    return newNode;
}

int eval(node* n){
    if(n==NULL) return 0;
    return n->val;
}

node* createVar(char var, int val){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->op = var;

    return newNode;
}

node* createAssgn(char var, node* val){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = eval(val);
    newNode->left = createVar(var, newNode->val);
    newNode->op = '=';
    newNode->right = val;

    return newNode;
}

node* createOp(char op, node* left, node* right){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->left = left;
    newNode->right = right;
    newNode->op = op;

    switch(op){
        case '+':
            newNode->val = eval(left) + eval(right);
            break;
        case '-':
            newNode->val = eval(left) - eval(right);
            break;
        case '*':
            newNode->val = eval(left) * eval(right);
            break;
        case '/':
            newNode->val = eval(left) / eval(right);
            break;
        default:
            newNode->val = 0;
    }
    

    return newNode;
}
node* createNum(int val){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->op = '_';

    return newNode;
}




int printTree(node* tree){
    if(tree==NULL) return 0;

    if(tree->left==NULL && tree->right==NULL){
        if(tree->op == '_') printf("%d ", tree->val);
        else printf("%c ", tree->op);
        return tree->val;
    }

    printf("%c ", tree->op);
    int x = printTree(tree->left) ;
    int y = printTree(tree->right);
    
    switch(tree->op){
        case '+':
            return x+y;
            break;
        case '-':
            return x-y;
            break;
        case '*':
            return x*y;
            break;
        case '/':
            return x/y;
            break;
        default:
            return 0;
    }
    
    return 0;
}


void evaluateTree(node* tree){
    printf("= %d\n", printTree(tree));
}

void printAssgn(node* tree){
    printf("%c = ", tree->left->op);
    evaluateTree(tree->right);
}



#endif