#ifndef __EXECUTE_TREE___
#define __EXECUTE_TREE___

#include <stdio.h>
#include <string.h>
#include "./dataTypes.hpp"
#include "./printTree2.hpp"

int execute_stmt_list(node* tree);



// void update_var(char* name, int val, int isArr=0, int index=0){
//     if(isArr){
//         symbol_table[name].data.arr[index] = val;
//     }
//     else 
//         symbol_table[name].data.num = val;      // not sure. to change
// }

int execute_stmt(node* tree){
    // RETURNS 1 IF IT HIT A BREAK STATEMENT
    // AND RETURN 2 IF HIT A CONTINUE STATEMETN
    // ELSE RETURNS 0

    if(tree == nullptr) return 0;

    if(tree->id_type==ASSIGN){
        if(tree->child == nullptr) return 0;  // empty assignment

        if(tree->child->child != nullptr){
            // array element
            update_var(tree->child->name, evaluate_expr(tree->child->next), 1, evaluate_expr(tree->child->child));
        }
        else
            update_var(tree->child->name, evaluate_expr(tree->child->next));
    }
    else if(tree->id_type==FUNC){
        if(strcmp(tree->name, "WRITE") == 0){
            printf("\n=> %d\n", evaluate_expr(tree->child->child)); // not sure. need to change
        }
    }
    else if(tree->id_type==IF_STMNT){
        if(evaluate_expr(tree->child)){
            int loopStatus = execute_stmt_list(tree->child->next);
            return loopStatus;
        }
        else{
            if(tree->child && tree->child->next){
                int loopStatus = execute_stmt_list(tree->child->next->next);
                return loopStatus;
            }
        }
    }
    else if(tree->id_type==FOR_STMNT){
        // printf("------------------\n");
        // print_stmt(tree->child);

        execute_stmt(tree->child);
        while(evaluate_expr(tree->child->next)){
            int loopStatus = execute_stmt_list(tree->child->next->next->next);    // statements inside for loop
            if(loopStatus == 1) break;  // it hit a break statement
            execute_stmt(tree->child->next->next);    // for loop increment part
        }
    }
    else if(tree->id_type==BREAK_STMNT)       return 1;
    else if(tree->id_type==CONTINUE_STMNT)    return 2;

    return 0;
}

int execute_stmt_list(node* tree){
    // RETURNS 1 IF IT HIT A BREAK STATEMENT
    // AND RETURN 2 IF HIT A CONTINUE STATEMETN
    // ELSE RETURNS 0

    if(tree == nullptr) return 0;
    if(tree->id_type != STATEMENT_LIST) {printf("ERROR: trying to execute which is not STATEMENT_LIST\n"); return 0;}

    tree = tree->child;
    if(tree == nullptr) return 0;
    if(tree->id_type != STATEMENT) {printf("ERROR: trying to execute which is not STATEMENT\n"); return 0;}

    while(tree){
        int loopStatus = execute_stmt(tree->child);
        if(loopStatus) return loopStatus;
        tree = tree->next;
    }

    return 0;
}




void declareVar(node* tree, _DATA_TYPES_ varDataType){
    if(tree == nullptr) return;
    if(tree->id_type != VARIABLE) {printf("ERROR: trying to declare which is not VARIABLE\n"); return;}

    struct SymbolEntry varSymbolEntry;
    varSymbolEntry.type = varDataType;
    switch(varDataType){
        case _INT_:
            if(tree->child != nullptr){
                varSymbolEntry.data.arr = (int*) malloc(sizeof(int) * evaluate_expr(tree->child));
            }
            else 
                varSymbolEntry.data.num = 0;
            break;
        
        case _BOOLEAN_:
            if(tree->child != nullptr)
                varSymbolEntry.data.arr = (int*) malloc(sizeof(int) * evaluate_expr(tree->child));
            else 
                varSymbolEntry.data.boolean = 0;
            break;
        
        default:
            printf("ERROR: trying to execute of unkonwn data type\n"); 
    }
    
    symbol_table[tree->name] = varSymbolEntry;
    variable_types[tree->name] = varDataType;
}

void execute_Ldecl_list(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != Ldecl_list) {printf("ERROR: trying to execute which is not Ldecl_list\n"); return;}

    tree = tree->child;
    // _DATA_TYPES_ varDataType = tree->val;
    _DATA_TYPES_ varDataType = static_cast<_DATA_TYPES_>(tree->val);
    tree = tree->next;
    while(tree){
        declareVar(tree, varDataType);
        tree = tree->next;
    }
}

void execute_Decl(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != DECLERATION) {printf("ERROR: trying to execute which is not decleration\n"); return;}

    tree = tree->child;
    while(tree){
        execute_Ldecl_list(tree);
        tree = tree->next;
    }
}


void execute_tree(node* tree){
    if(tree == nullptr) return;

    execute_Decl(tree->child);

    if(tree->child){
        printf("\nOUTPUT:\n");
        execute_stmt_list(tree->child->next);
    }
}





#endif
