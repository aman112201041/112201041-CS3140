#ifndef __PRINT_TREE__
#define __PRINT_TREE__

#include "./dataTypes.hpp"

#include <stdio.h>
#include <string.h>

void print_stmt_list(node* tree, int level);

void print_tabs(int n){
    for(int i=0; i<n; i++) printf("\t");
}

void print_indent(int level){
    // if(level < 1) level = 1;
    // print_tabs(level-1);
    // printf("|");
    // printf("_______");

    if(level <= 1) return;
    print_tabs(level-2);
    printf("|");
    printf("_______");
}


void printNode(node* n){
    if(n == nullptr) return;
    switch(n->id_type){
        case(VARIABLE):
            // if(n->child){
            //     // array
            //     if(n->child->next) {
            //         // 2d array
            //         printf("VAR( %s[%d][%d] ) ", n->name, evaluate_expr(n->child), evaluate_expr(n->child->next));
            //     }
            //     else {
            //         // 1d array
            //         printf("VAR( %s[%d] ) ", n->name, evaluate_expr(n->child));
            //     }
            //     break;
            // }
            printf("VAR(%s) ", n->name);
            break;
        case(NUMBER):
            printf("NUM(%d) ", n->val);
            break;
        case(FLOATNUMBER):
            printf("float(%f) ", n->fval);
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

void print_stmt(node* tree, int level){
    if(tree == nullptr) return;

    // print_indent(level);
    // printf("STATEMENT \n");
    
    if(tree->id_type==ASSIGN){
        print_indent(level);
        printf("ASSIGN ");
        if(tree->child){
            printNode(tree->child);
            printf(" <= ");
            if(tree->child->next)
                print_expression(tree->child->next);
        }
    }
    
    else if(tree->id_type==FUNC){
        print_indent(level);
        if(strcmp(tree->name, "WRITE") == 0){
            printf("WRITE <= ");
            print_expression(tree->child->child);   // write function have only one argument
            // printf(" => %d\n", evaluate(tree->next));
        }
    }

    else if(tree->id_type==IF_STMNT){
        node* expr = tree->child;
        print_indent(level);
        printf("IF \n");
        print_indent(level+1);
        print_expression(expr);
        printf("\n");
        print_indent(level+1);
        printf("THEN\n");

        if(expr == nullptr) return;

        print_stmt_list(expr->next, level+2);

        if(expr->next == nullptr) return;

        if(expr->next->next){
            print_indent(level);
            printf("ELSE\n");
            print_stmt_list(expr->next->next, level+1);
        }
    }

    else if(tree->id_type==FOR_STMNT){
        print_indent(level);
        printf("FOR\n");
        print_stmt(tree->child, level+1);
        // printf("TILL: ");
        print_indent(level+1);
        print_expression(tree->child->next);
        printf("\n");
        // printf("REDO: ");
        print_stmt(tree->child->next->next, level+1);
        
        print_indent(level+1);
        printf("inside for:\n");
        print_stmt_list(tree->child->next->next->next, level+3);
    }
    else if(tree->id_type==WHILE_STMNT){
        print_indent(level);
        printf("DO\n");
        print_stmt_list(tree->child, level+1);
        print_indent(level);
        printf("WHILE\n");
        print_indent(level+1);
        print_expression(tree->child->next);
    }
    else if(tree->id_type==BREAK_STMNT)       {print_indent(level); printf("BREAK");}
    else if(tree->id_type==CONTINUE_STMNT)    {print_indent(level); printf("CONTINUE");}

    printf("\n");
}

void print_stmt_list(node* tree, int level){
    if(tree == nullptr) return;
    if(tree->id_type != STATEMENT_LIST) {printf("ERROR: trying to print which is not STATEMENT_LIST\n"); return;}

    tree = tree->child;
    if(tree == nullptr) return;
    if(tree->id_type != STATEMENT) {printf("ERROR: trying to print which is not STATEMENT\n"); return;}

    while(tree){
        print_stmt(tree->child, level);
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
            print_stmt_list(tree->child->next, 1);
    }
}


#endif