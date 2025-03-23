#ifndef __PRINT_TREE__
#define __PRINT_TREE__

#include "./dataTypes.hpp"

#include <stdio.h>
#include <string.h>

void print_stmt_list(node* tree);


void printNode(node* n){
    if(n == nullptr) return;
    switch(n->id_type){
        case(VARIABLE):
            printf("VAR(%s) ", n->name);
            break;
        case(NUMBER):
            printf("NUM(%d) ", n->val);
            break;
        case(OP):
            printf("OP(%s) ", n->name);
            break;
        case(KEY_WORD):
            printf("KEY_WORD(%s) ", n->name);
            break;
        case(FUNC):
            printf("CALL %s  ", n->name);
            break;
        case(DECLERATION):
            printf("DECL ");
            break;
        default:
            printf("some error while printing");
            return;
    }
}

void print_expression(node* tree){
    if(tree==nullptr) return;
    printNode(tree);
    tree = tree->child;
    while(tree){
        print_expression(tree);
        tree = tree->next;
    }
}

void print_stmt(node* tree){
    if(tree == nullptr) return;

    printf("\nSTATEMENT \n");
    if(tree->id_type==ASSIGN){
        printf("ASSIGN ");
        if(tree->child){
            printNode(tree->child);
            if(tree->child->next)
                print_expression(tree->child->next);
        }
        printf("\n");
    }
    
    else if(tree->id_type==FUNC){
        if(strcmp(tree->name, "WRITE") == 0){
            printf("WRITE ");
            print_expression(tree->child->child);   // write function have only one argument
            // printf(" => %d\n", evaluate(tree->next));
        }
    }

    else if(tree->id_type==IF_STMNT){
        node* expr = tree->child;
        printf("IF (");
        print_expression(expr);
        printf(") THEN:");

        if(expr == nullptr) return;

        print_stmt_list(expr->next);

        if(expr->next == nullptr) return;

        if(expr->next->next){
            printf("ELSE:");
            print_stmt_list(expr->next->next);
        }
    }

    else if(tree->id_type==FOR_STMNT){
        printf("FOR: ");
        print_stmt(tree->child);
        printf("TILL: ");
        print_expression(tree->child->next);
        printf("REDO: ");
        print_stmt(tree->child->next->next);
        printf("inside for:");
        print_stmt_list(tree->child->next->next->next);
    }
    else if(tree->id_type==BREAK_STMNT)       printf("BREAK");
    else if(tree->id_type==CONTINUE_STMNT)    printf("CONTINUE");

    printf("\n");
}

void print_stmt_list(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != STATEMENT_LIST) {printf("ERROR: trying to print which is not STATEMENT_LIST\n"); return;}

    tree = tree->child;
    if(tree == nullptr) return;
    if(tree->id_type != STATEMENT) {printf("ERROR: trying to print which is not STATEMENT\n"); return;}

    while(tree){
        print_stmt(tree->child);
        tree = tree->next;
    }
}





void print_Lid_list(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != VARIABLE) {printf("ERROR: trying to print which is not VARIABLE\n"); return;}

    while(tree){
        printNode(tree);
        tree = tree->next;
    }
}

void print_Ldecl_list(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != Ldecl_list) {printf("ERROR: trying to print which is not Ldecl_list\n"); return;}

    printNode(tree->child);
    print_Lid_list(tree->child->next);
    printf("\n");
}

void print_Decl(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != DECLERATION) {printf("ERROR: trying to print which is not decleration\n"); return;}

    printf("DECL\n");

    tree = tree->child;
    while(tree){
        print_Ldecl_list(tree);
        tree = tree->next;
    }
    printf("\n");
}

void print_tree(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != TOP) {printf("ERROR: something went wrong. first node is not TOP type\n"); return;}

    if(tree->child){
        print_Decl(tree->child);
        if(tree->child->next)
            print_stmt_list(tree->child->next);
    }
}


#endif