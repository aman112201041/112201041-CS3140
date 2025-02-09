#ifndef __DATA_TYPES___
#define __DATA_TYPES___

#include <stdio.h>
#include <string.h>


enum identifier{
    VARIABLE,
    NUMBER,
    OP,
    KEY_WORD,
    FUNC,
    DECLERATION,
    Ldecl_list,
    STATEMENT,
    ASSIGN
};

typedef struct node{
    int val;
    enum identifier id_type;
    char* name;
    struct node* child;
    struct node* next;
    struct node* rightMostChld;
} node;

node* createStatement(){
    node* newNode = new node;
    newNode->id_type = STATEMENT;
    newNode->name = "#";
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createLdecl_list(){
    node* newNode = new node;
    newNode->id_type = Ldecl_list;
    newNode->name = "#";
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

int evaluate(node* n){
    if(n == nullptr){return 0;}
    return n->val;
}

int evaluateOp(char* op, node* operand1, node* operand2){
    int x = evaluate(operand1);
    int y = evaluate(operand2);

    if(strcmp(op, "+") == 0) return x+y;
    else if(strcmp(op, "-") == 0) return x-y;
    else if(strcmp(op, "*") == 0) return x*y;
    else if(strcmp(op, "/") == 0) return x/y;
   
   return 0;
}

node* createOp(char* op, node* operand1, node* operand2){
    node* newNode = new node;
    newNode->id_type = OP;
    newNode->name = op;
    newNode->child = operand1;
    newNode->next = nullptr;
    operand1->next = operand2;
    int value = evaluateOp(op, operand1, operand2);
    newNode->val = value;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createNum(int val){
    node* newNode = new node;
    newNode->id_type = NUMBER;
    newNode->name = "#";
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = val;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createDecl(){
    node* newNode = new node;
    newNode->id_type = DECLERATION;
    newNode->name = "#";
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createVar(char* var, int val){
    node* newNode = new node;
    newNode->id_type = VARIABLE;
    newNode->name = var;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = val;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createKeyword(char* key_word){
    node* newNode = new node;
    newNode->id_type = KEY_WORD;
    newNode->name = key_word;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createFunc(char* func_name){
    node* newNode = new node;
    newNode->id_type = FUNC;
    newNode->name = func_name;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createAssign(node* var, node* expr){
    node* newNode = new node;
    newNode->id_type = ASSIGN;
    newNode->name = nullptr;
    newNode->child = var;
    newNode->child->next = expr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = newNode->child->next;
    return newNode;
}

void pushChildNode(node* parent, node* child){
    if(parent == nullptr) {printf("node is null\n"); return;}
    if(parent->child == nullptr) {
        parent->child = child;
        parent->rightMostChld = parent->child;
        return;
    }
    parent->rightMostChld->next = child;
    parent->rightMostChld = parent->rightMostChld->next;
    return;
}

void pushNextNode(node* curr, node* next){
    if(curr == nullptr) {printf("node is null\n"); return;}
    curr->next = next;
    return;
}

// enum identifier{
//     VAR,
//     NUM,
//     OP,
//     KEY_WORD,
//     FUNC,
//     DECLERATION
// };


// void printNode(node* n){
//     if(n == nullptr) return;
//     switch(n->id_type){
//         case(VARIABLE):
//             printf("VAR(%s) ", n->name);
//             break;
//         case(NUMBER):
//             printf("NUM(%d) ", n->val);
//             break;
//         case(OP):
//             printf("OP(%s) ", n->name);
//             break;
//         case(KEY_WORD):
//             printf("KEY_WORD(%s) ", n->name);
//             break;
//         case(FUNC):
//             printf("CALL(%s) ", n->name);
//             break;
//         case(DECLERATION):
//             printf("DECL ");
//             break;
//         default:
//             printf("some error while printing");
//             return;
//     }
// }


// void printNextNodes(node* n){
//     while(n != nullptr){
//         printNode(n);
//         n = n->next;
//     }
// }

// void printTree(node* n){
//     if(n == nullptr) return;
//     while(n != nullptr){
//         printNextNodes(n);
//         printf("\n");
//         n = n->child;
//     }
//     printf("\n");
// }


#endif
