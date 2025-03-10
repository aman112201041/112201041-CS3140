#ifndef __DATA_TYPES___
#define __DATA_TYPES___

#include <stdio.h>
#include <string.h>
// #include "./executeTree.hpp"


enum identifier{
    VARIABLE,
    NUMBER,                     // for constant numbers and for indexing.
    OP,
    KEY_WORD,                   // for now, keywords are only used for data types
    FUNC,
    DECLERATION,
    Ldecl_list,
    STATEMENT,
    ASSIGN,
    FUNC_ARGUMENT,
    IF_STMNT,
    STATEMENT_LIST,
    TOP,
    FOR_STMNT,
    BREAK_STMNT,
    CONTINUE_STMNT,
    WHILE_STMNT,
    FLOATNUMBER, 
};

typedef struct node{
    int val;                    // holds value of a number or data type of a variable
    enum identifier id_type;
    char* name;
    struct node* child;
    struct node* next;
    struct node* rightMostChld;

    float fval;
} node;



enum _DATA_TYPES_{
    _INT_,
    _ARRAY_,
    _BOOLEAN_,
    _ARRAY2D_,
    _FLOAT_,
    _FLOATNUMBER_,
};

union geek { 
    int num; 
    int* arr;
    int boolean;
    int** arr2d;
    float fnum;
    float* farr;
    float** farr2d;
};

struct SymbolEntry {
    _DATA_TYPES_ type;
    geek data;
};

map<string, SymbolEntry> symbol_table;

map<string, _DATA_TYPES_> variable_types;


void update_var(char* name, int val, int isArr=0, int index=0){
    if(isArr == -1){
        symbol_table[name].data.arr[index] = val;
    }
    else if(isArr == 0){
        symbol_table[name].data.num = val;      // not sure. to change
    }
    else {
        symbol_table[name].data.arr2d[isArr-1][index] = val;
    }

}

void update_var(char* name, float val, int isArr=0, int index=0){
    // printf("----- %s = %f ------", name, val);
    if(isArr == -1){
        symbol_table[name].data.farr[index] = val;
    }
    else if(isArr == 0){
        symbol_table[name].data.fnum = val;      // not sure. to change
    }
    else {
        symbol_table[name].data.farr2d[isArr-1][index] = val;
    }

}

struct SymbolEntry get_variable_value(char* name, int isArr=0, int index=0){
    struct SymbolEntry expr_val;
    expr_val.type = _INT_;
    expr_val.data.num = 0;

    if (symbol_table.find(name) == symbol_table.end()){
        printf("\n ERROR: variable %s not found in symbol table\n", name);
        return expr_val;
    }

    switch(symbol_table[name].type){
        case _INT_:
            expr_val.type = _INT_;
            if(isArr == -1){
                expr_val.data.num = symbol_table[name].data.arr[index];
            }
            else if(isArr == 0){
                expr_val.data.num = symbol_table[name].data.num;
            }
            else{
                expr_val.data.num = symbol_table[name].data.arr2d[isArr-1][index];
            }
            return expr_val;
        
        case _FLOAT_:
            expr_val.type = _FLOAT_;
            if(isArr == -1){
                expr_val.data.fnum = symbol_table[name].data.farr[index];
            }
            else if(isArr == 0){
                expr_val.data.fnum = symbol_table[name].data.fnum;
                printf(" %s=%f ", name, symbol_table[name].data.fnum);
                // printf(" xxx %s = %f %f xxx ", name, expr_val.data.fnum, symbol_table[name].data.fnum);
            }
            else{
                expr_val.data.fnum = symbol_table[name].data.farr2d[isArr-1][index];
                // printf(" xxx %s = %f %f xxx ", name, expr_val.data.fnum, symbol_table[name].data.farr2d[isArr-1][index]);
            }
            return expr_val;
        
        // case _BOOLEAN_:
        //     if(isArr)
        //         return symbol_table[name].data.arr[index];
        //     else
        //         return symbol_table[name].data.boolean;

        default:
            printf("\n ERROR: variable %s is not an int, array or boolean\n", name);
    }

    return expr_val;
}





node* createCopyNode(node* n){
    if(n==nullptr) return nullptr;
    
    node* newNode = new node;
    
    newNode->val = n->val;
    newNode->id_type = n->id_type;
    newNode->name = strdup(n->name);
    
    newNode->child = createCopyNode(n->child);
    newNode->next = createCopyNode(n->next);
    newNode->rightMostChld = createCopyNode(n->rightMostChld);

    return newNode;
}

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

node* createFunctionArgument(){
    node* newNode = new node;
    newNode->id_type = FUNC_ARGUMENT;
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



struct SymbolEntry evaluateOp(char* op, struct SymbolEntry x, struct SymbolEntry y){
    struct SymbolEntry expr_val;
    expr_val.type = _INT_;
    expr_val.data.num = 0;

    if(strcmp(op, "+") == 0) {
        expr_val.type = x.type;
        if(x.type == _INT_){
            expr_val.data.num = x.data.num + y.data.num;
        }
        else if(x.type == _FLOAT_){
            expr_val.data.fnum = x.data.fnum + y.data.fnum;
        }
        
        return expr_val;
    }
    // else if(strcmp(op, "-") == 0)   return y-x;   //because of unary. not sure
    else if(strcmp(op, "-") == 0) {
        expr_val.type = x.type;
        if(x.type == _INT_){
            expr_val.data.num = y.data.num - x.data.num;
        }
        else if(x.type == _FLOAT_){
            expr_val.data.fnum = y.data.fnum - x.data.fnum;
        }
        
        return expr_val;
    }
    else if(strcmp(op, "*") == 0) {
        expr_val.type = x.type;
        if(x.type == _INT_){
            expr_val.data.num = x.data.num * y.data.num;
        }
        else if(x.type == _FLOAT_){
            expr_val.data.fnum = x.data.fnum * y.data.fnum;
        }
        
        return expr_val;
    }
    else if(strcmp(op, "/") == 0) {
        expr_val.type = x.type;
        if(x.type == _INT_){
            expr_val.data.num = x.data.num / y.data.num;
        }
        else if(x.type == _FLOAT_){
            expr_val.data.fnum = x.data.fnum / y.data.fnum;
        }
        
        return expr_val;
    }
    else if(strcmp(op, ">") == 0) {
        expr_val.type = _INT_;
        if(x.type == _INT_){
            if(x.data.num > y.data.num){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        else if(x.type == _FLOAT_){
            if(x.data.fnum > y.data.fnum){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        
        return expr_val;
    }
    else if(strcmp(op, "<") == 0) {
        expr_val.type = _INT_;
        if(x.type == _INT_){
            if(x.data.num < y.data.num){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        else if(x.type == _FLOAT_){
            if(x.data.fnum < y.data.fnum){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        
        return expr_val;
    }
    else if(strcmp(op, ">=") == 0) {
        expr_val.type = _INT_;
        if(x.type == _INT_){
            if(x.data.num >= y.data.num){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        else if(x.type == _FLOAT_){
            if(x.data.fnum >= y.data.fnum){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        
        return expr_val;
    }
    else if(strcmp(op, "<=") == 0) {
        expr_val.type = _INT_;
        if(x.type == _INT_){
            if(x.data.num <= y.data.num){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        else if(x.type == _FLOAT_){
            if(x.data.fnum <= y.data.fnum){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        
        return expr_val;
    }
    else if(strcmp(op, "==") == 0) {
        expr_val.type = _INT_;
        if(x.type == _INT_){
            if(x.data.num == y.data.num){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        else if(x.type == _FLOAT_){
            if(x.data.fnum == y.data.fnum){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        
        return expr_val;
    }
    else if(strcmp(op, "!=") == 0) {
        expr_val.type = _INT_;
        if(x.type == _INT_){
            if(x.data.num != y.data.num){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        else if(x.type == _FLOAT_){
            if(x.data.fnum != y.data.fnum){
                expr_val.type = _INT_;
                expr_val.data.num = 1;
            }
            else{
                expr_val.type = _INT_;
                expr_val.data.num = 0;
            }
        }
        
        return expr_val;
    }
    else if(strcmp(op, "++") == 0) {
        expr_val.type = x.type;
        if(x.type == _INT_){
            expr_val.data.num = x.data.num + 1;
        }
        else if(x.type == _FLOAT_){
            expr_val.data.fnum = x.data.fnum + 1;
        }
        
        return expr_val;
    }
   
   return expr_val;
}



struct SymbolEntry evaluate_expr(node* tree){
    struct SymbolEntry expr_val;
    expr_val.type = _INT_;
    expr_val.data.num = 0;
    
    if(tree == nullptr) return expr_val;

    switch(tree->id_type){
        case VARIABLE:
            if(tree->child){
                // array
                if(tree->child->next){
                    // 2d array
                    return get_variable_value(tree->name, evaluate_expr(tree->child).data.num+1, evaluate_expr(tree->child->next).data.num);
                }
                else {
                    // 1d array

                    return get_variable_value(tree->name, -1, evaluate_expr(tree->child).data.num);
                }
            }
            else{
                // non array
                return get_variable_value(tree->name);
            }
        
        case NUMBER:
            expr_val.type = _INT_;
            expr_val.data.num = tree->val;
            return expr_val;
        case FLOATNUMBER:
            expr_val.type = _FLOAT_;
            expr_val.data.fnum = tree->fval;
            // printf("xxx %f %f xxx", tree->fval, expr_val.data.fnum);
            return expr_val;
        
        case OP:
            // if(strcmp(tree->name, "++") == 0) {
            //     int temp = evaluate_expr(tree->child);
            //     if(tree->child->child != nullptr){
            //         // array element
            //         update_var(tree->child->name, temp+1, 1, evaluate_expr(tree->child->child));
            //     }
            //     else
            //         update_var(tree->child->name, temp+1);

            //     return temp;
            // }
            return evaluateOp(tree->name, evaluate_expr(tree->child), evaluate_expr(tree->child->next));
        
        default:
            printf("\nERROR: SOMETHING OTHER THAN VARIABLE, NUMBER OR OPERATOR IS PRESENT IN EXPRESSION\n");
    }
    return expr_val;
}



node* createOp(char* op, node* operand1, node* operand2){
    node* newNode = new node;
    newNode->id_type = OP;
    newNode->name = op;
    newNode->child = operand1;
    newNode->next = nullptr;
    operand1->next = operand2;
    // int value = evaluateOp(op, operand1, operand2);
    // newNode->val = value;
    newNode->val = 0;
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

node* createFloat(float val){
    node* newNode = new node;
    newNode->id_type = FLOATNUMBER;
    newNode->fval = val;

    newNode->name = "#";
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = -11111;
    
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

// to change
node* createVar(char* var){
    node* newNode = new node;
    newNode->id_type = VARIABLE;
    newNode->name = var;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->rightMostChld = nullptr;
    newNode->val = 0;
    return newNode;
}

node* createKeyword(char* name, int val){
    node* newNode = new node;
    newNode->id_type = KEY_WORD;
    newNode->name = name;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = val;
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
    newNode->child = var;
    newNode->name = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;

    if(var)
        newNode->child->next = expr;

    // if(expr)
    //     newNode->rightMostChld = expr->rightMostChld;       // not sure!!!
    // newNode->rightMostChld = newNode->child->next;       // not sure!!!
    newNode->rightMostChld = expr;
    
    return newNode;
}

node* createBreak(){
    node* newNode       = new node;
    newNode->id_type    = BREAK_STMNT;
    newNode->child      = nullptr;
    newNode->name       = nullptr;
    newNode->next       = nullptr;
    newNode->val        = 0;
    return newNode;
}
node* createContinue(){
    node* newNode       = new node;
    newNode->id_type    = CONTINUE_STMNT;
    newNode->child      = nullptr;
    newNode->name       = nullptr;
    newNode->next       = nullptr;
    newNode->val        = 0;
    return newNode;
}

node* createIfStmnt(){
    node* newNode = new node;
    newNode->id_type = IF_STMNT;
    newNode->name = nullptr;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createForStmnt(){
    node* newNode = new node;
    newNode->id_type = FOR_STMNT;
    newNode->name = nullptr;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createWhileStmnt(){
    node* newNode = new node;
    newNode->id_type = WHILE_STMNT;
    newNode->name = nullptr;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createStmntList(){
    node* newNode = new node;
    newNode->id_type = STATEMENT_LIST;
    newNode->name = nullptr;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
    return newNode;
}

node* createTop(){
    node* newNode = new node;
    newNode->id_type = TOP;
    newNode->name = nullptr;
    newNode->child = nullptr;
    newNode->next = nullptr;
    newNode->val = 0;
    newNode->rightMostChld = nullptr;
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





#endif
