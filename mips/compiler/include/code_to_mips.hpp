#ifndef __CODE_TO_MIPS___
#define __CODE_TO_MIPS___

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./dataTypes.hpp"
#include "./printTree2.hpp"



#define MAX_STACK_SIZE 200

const char* break_label_stack[MAX_STACK_SIZE];
int break_stack_top = -1;


extern FILE *yyin;
extern FILE *yyout;

int compile_stmt_list(node* tree);
int calculate_expr_asm(node* tree);

const char* reg_stack[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
int reg_free[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int availabe_label_number = 2;

int log10(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

void push_break_label(const char* label) {
    if (break_stack_top < MAX_STACK_SIZE - 1) {
        break_label_stack[++break_stack_top] = label;
    } else {
        fprintf(stderr, "Break label stack overflow!\n");
    }
}

void pop_break_label() {
    if (break_stack_top >= 0) {
        break_stack_top--;
    } else {
        fprintf(stderr, "Break label stack underflow!\n");
    }
}

const char* top_break_label() {
    if (break_stack_top >= 0) {
        return break_label_stack[break_stack_top];
    } else {
        return NULL;
    }
}


char* get_free_label(){
    char* label = (char*) malloc(10 + log10(availabe_label_number));
    sprintf(label, "L%d", availabe_label_number++);
    return label;
}

int get_reg() {
    for (int i = 0; i < 10; i++) {
        if (reg_free[i]) {
            reg_free[i] = 0;
            return i;
        }
    }
    fprintf(stderr, "Out of registers! (evaluating expression)\n");
    exit(1);
    return -1;
}

void free_reg(int reg_num) {
    if (reg_num < 0 || reg_num >= 10) {
        fprintf(stderr, "Invalid register number: %d\n", reg_num);
        return;
    }
    reg_free[reg_num] = 1;
}

int calculate_expr_asm(node* tree){
    // It returns the temperory register number that hold the result of the expression

    if(tree == nullptr) return -1;

    if(tree->id_type == NUMBER){
        int val = tree->val;
        int free_temp_reg = get_reg();
        const char* asm_code = "\tli	%s,%d\n";
        fprintf(yyout, asm_code, reg_stack[free_temp_reg], val);
        return free_temp_reg;
    }
    else if(tree->id_type == OP){
        char* op = tree->name;
        if(strcmp(op, "+") == 0)        {
                                            int free_temp_reg = get_reg();
                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);
                                            const char* asm_code = "\taddu %s, %s, %s\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_left], reg_stack[R_right]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "-") == 0)   {   //because of unary. not sure
                                            int free_temp_reg = get_reg();
                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                            node* right_child = left_child->next;
                                            if(right_child){
                                                int R_right = calculate_expr_asm(right_child);
                                                const char* asm_code = "\tsub %s, %s, %s\n";
                                                fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_right], reg_stack[R_left]);
                                                free_reg(R_right);
                                                free_reg(R_left);
                                            }
                                            else{
                                                const char* asm_code = "\tsub %s, $zero, %s\n";
                                                fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_left]);
                                                free_reg(R_left);
                                            }
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "*") == 0)   {
                                            int free_temp_reg = get_reg();
                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);
                                            fprintf(yyout, "\tmult %s, %s\n", reg_stack[R_left], reg_stack[R_right]);
                                            fprintf(yyout, "\tmflo %s\n", reg_stack[free_temp_reg]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "/") == 0)   {
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);  // numerator
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);  // denominator

                                            const char* asm_code = "\tdiv %s, %s\n\tbne	%s,$0,1f\n\tnop\n\tbreak	7\n1:\n\tmflo %s\n";
                                            fprintf(yyout, asm_code, reg_stack[R_left], reg_stack[R_right], reg_stack[R_right], reg_stack[free_temp_reg]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, ">") == 0)   { 
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);

                                            const char* asm_code = "\tslt %s, %s, %s\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_right], reg_stack[R_left]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "<") == 0)   { 
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);

                                            const char* asm_code = "\tslt %s, %s, %s\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_left], reg_stack[R_right]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, ">=") == 0)  { 
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);

                                            const char* asm_code = "\tslt %s, %s, %s\n\txori %s, %s, 1\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_left], reg_stack[R_right], reg_stack[free_temp_reg], reg_stack[free_temp_reg]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "<=") == 0)  { 
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);

                                            const char* asm_code = "\tslt %s, %s, %s\n\txori %s, %s, 1\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_right], reg_stack[R_left], reg_stack[free_temp_reg], reg_stack[free_temp_reg]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "==") == 0)  {
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);

                                            const char* asm_code = "\nxor %s, %s, %s\n\tsltiu %s, %s, 1\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_left], reg_stack[R_right], reg_stack[free_temp_reg], reg_stack[free_temp_reg]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "!=") == 0)  {
                                            int free_temp_reg = get_reg();

                                            node* left_child = tree->child;
                                            int R_left = calculate_expr_asm(left_child);
                                        
                                            node* right_child = left_child->next;
                                            int R_right = calculate_expr_asm(right_child);

                                            const char* asm_code = "\nxor %s, %s, %s\n\tsltu %s, $zero, %s\n";
                                            fprintf(yyout, asm_code, reg_stack[free_temp_reg], reg_stack[R_left], reg_stack[R_right], reg_stack[free_temp_reg], reg_stack[free_temp_reg]);
                                            free_reg(R_left);
                                            free_reg(R_right);
                                            return free_temp_reg;
                                        }
        else if(strcmp(op, "++") == 0) {
                                            node* var_node = tree->child;
                                            const char* var_name = var_node->name;

                                            bool array = false;
                                            if(tree->child->child != nullptr) {
                                                array = true;
                                            }

                                            if(array){
                                                int index_reg = calculate_expr_asm(tree->child->child);
                                                int reg_addr = get_reg();
                                                int value_reg = get_reg();
                                                fprintf(yyout, "\tla %s, %s\n", reg_stack[reg_addr], var_name);
                                                fprintf(yyout, "\tsll %s, %s, 2\n", reg_stack[index_reg], reg_stack[index_reg]);
                                                fprintf(yyout, "\tadd %s, %s, %s\n", reg_stack[reg_addr], reg_stack[reg_addr], reg_stack[index_reg]);

                                                fprintf(yyout, "\tlw %s, 0(%s)\n", reg_stack[value_reg], reg_stack[reg_addr]);
                                                fprintf(yyout, "\taddi %s, %s, 1\n", reg_stack[index_reg], reg_stack[value_reg]);
                                                fprintf(yyout, "\tsw %s, 0(%s)\n", reg_stack[index_reg], reg_stack[reg_addr]);
                                                free_reg(index_reg);
                                                free_reg(reg_addr);
                                                return value_reg;
                                            }
                                            else{
                                                int reg_addr = get_reg();
                                                int value_reg = get_reg();
                                                int temp_reg = get_reg();
                                                fprintf(yyout, "\tla %s, %s\n", reg_stack[reg_addr], var_name);
                                                fprintf(yyout, "\tlw %s, 0(%s)\n", reg_stack[value_reg], reg_stack[reg_addr]);
                                                fprintf(yyout, "\taddi %s, %s, 1\n", reg_stack[temp_reg], reg_stack[value_reg]);
                                                fprintf(yyout, "\tsw %s, 0(%s)\n", reg_stack[temp_reg], reg_stack[reg_addr]);
                                                free_reg(temp_reg);
                                                free_reg(reg_addr);
                                                return value_reg;
                                            }
                                            return -1;
                                        }
    }
    else if(tree->id_type == VARIABLE){
        if(tree->child){
            // array
            int base_reg = get_reg();        
            int index_reg = calculate_expr_asm(tree->child);  
            int value_reg = get_reg();        

            fprintf(yyout, "\tla\t%s, %s\n", reg_stack[base_reg], tree->name);                
            fprintf(yyout, "\tsll\t%s, %s, 2\n", reg_stack[index_reg], reg_stack[index_reg]); 
            fprintf(yyout, "\tadd\t%s, %s, %s\n", reg_stack[value_reg], reg_stack[base_reg], reg_stack[index_reg]);  
            fprintf(yyout, "\tlw\t%s, 0(%s)\n", reg_stack[value_reg], reg_stack[value_reg]);   

            free_reg(base_reg);
            free_reg(index_reg);
            return value_reg;
        }
        else{
            // non array
            int free_temp_reg = get_reg();
            const char* asm_code = "\tla	%s,%s\n\tlw	%s,0(%s)\n";
            fprintf(yyout, asm_code, reg_stack[free_temp_reg], tree->name, reg_stack[free_temp_reg], reg_stack[free_temp_reg]);
            return free_temp_reg;
        }
    }
    
    return -1;
}

void compile_write_expr(node* tree){
    if(tree == nullptr) return;
    int reg_num = calculate_expr_asm(tree);
    const char* print_asm = "\tmove	$5,%s\n\tla	$4,$LC1\n\tjal	printf\n";
    fprintf(yyout, print_asm, reg_stack[reg_num]);
    free_reg(reg_num);
}

void compile_read_var_expr(node* tree){
    if(tree == nullptr) return;
    if(tree->child){
        int index_reg = calculate_expr_asm(tree->child);

        const char* read_asm = 
            "\tla $2, %s\n"
            "\tsll %s, %s, 2\n"      
            "\tadd $5, $2, %s\n"
            "\tla $4, $LC0\n"
            "\tjal __isoc99_scanf\n";

        fprintf(yyout, read_asm,
                tree->name,             
                reg_stack[index_reg],   
                reg_stack[index_reg],   
                reg_stack[index_reg]);  

        free_reg(index_reg);
    }
    else{
        // non array
        const char* read_asm = "\tla	$5,%s\n\tla	$4,$LC0\n\tjal	__isoc99_scanf\n";
        fprintf(yyout, read_asm, tree->name);
    }
}

int compile_stmt(node* tree){

    if(tree == nullptr) return 0;

    if(tree->id_type==ASSIGN){
        if(tree->child == nullptr) return 0;  // empty assignment

        if(tree->child->child != nullptr){
            // array element
            int index_reg = calculate_expr_asm(tree->child->child);
            int expr_reg = calculate_expr_asm(tree->child->next);

            fprintf(yyout, "\tla $2, %s\n", tree->child->name); // use reg_stack[0] as temp
            fprintf(yyout, "\tsll %s, %s, 2\n", reg_stack[index_reg], reg_stack[index_reg]); // index * 4
            fprintf(yyout, "\tadd $2, $2, %s\n", reg_stack[index_reg]);
            fprintf(yyout, "\tsw %s, 0($2)\n", reg_stack[expr_reg]);

            free_reg(index_reg);
            free_reg(expr_reg);
        }
        else{
            int expr_reg = calculate_expr_asm(tree->child->next);
            fprintf(yyout, "\tla $2, %s\n", tree->child->name);
            fprintf(yyout, "\tsw %s, 0($2)\n", reg_stack[expr_reg]);
            free_reg(expr_reg);
        }
    }
    else if(tree->id_type==FUNC){
        if(strcmp(tree->name, "WRITE") == 0){
            // printf("\n=> %d\n", evaluate_expr(tree->child->child)); // not sure. need to change
            node* argument = tree->child->child;
            while(argument){
                compile_write_expr(argument);
                argument = argument->next;
            }
        }
        else if(strcmp(tree->name, "READ") == 0){
            node* argument = tree->child->child;
            while(argument){
                compile_read_var_expr(argument);
                argument = argument->next;
            }
        }
    }
    else if(tree->id_type==IF_STMNT){
        if(tree->child){
            if(tree->child->next){
                if(tree->child->next->next){
                    // IF ELSE STATEMENT
                    int reg_condition_value = calculate_expr_asm(tree->child);
                    const char* else_label = get_free_label();
                    const char* end_if_label = get_free_label();

                    const char* asm_code_check = "\tbeq %s, $zero, %s\n";
                    fprintf(yyout, asm_code_check, reg_stack[reg_condition_value], else_label);

                    compile_stmt_list(tree->child->next);

                    const char* asm_code_jump_to_end = "\tj %s\n";
                    fprintf(yyout, asm_code_jump_to_end, end_if_label);

                    const char* asm_code_else_label = "\t%s:\n";
                    fprintf(yyout, asm_code_else_label, else_label);

                    compile_stmt_list(tree->child->next->next);

                    const char* asm_code_end_label = "\t%s:\n";
                    fprintf(yyout, asm_code_end_label, end_if_label);

                    free_reg(reg_condition_value);
                }
                else{
                    // IF STATEMENT
                    int reg_condition_value = calculate_expr_asm(tree->child);
                    const char* end_if_label = get_free_label();

                    const char* asm_code_check = "\tbeq %s, $zero, %s\n";
                    fprintf(yyout, asm_code_check, reg_stack[reg_condition_value], end_if_label);
                    compile_stmt_list(tree->child->next);
                    const char* asm_code_end = "\t%s:\n";
                    fprintf(yyout, asm_code_end, end_if_label);

                    free_reg(reg_condition_value);
                }
            }
            else{
                printf("ERROR: IF statement is not valid\n");
                return 0;
            }
        }
        else{
            printf("ERROR: IF statement is not valid\n");
            return 0;
        }
    }
    else if(tree->id_type == FOR_STMNT) {
        compile_stmt(tree->child);
    
        const char* cond_label = get_free_label();  // label for condition check
        const char* body_label = get_free_label();  // label for loop body
        const char* end_label  = get_free_label();  // label for loop exit
        push_break_label(end_label);
    
        fprintf(yyout, "\tj %s\n", cond_label);
    
        fprintf(yyout, "%s:\n", body_label);
        compile_stmt_list(tree->child->next->next->next); // body
    
        compile_stmt(tree->child->next->next); // update
    
        fprintf(yyout, "%s:\n", cond_label);
        int cond_reg = calculate_expr_asm(tree->child->next); // condition
    
        fprintf(yyout, "\tbne %s, $zero, %s\n", reg_stack[cond_reg], body_label);
        free_reg(cond_reg);
    
        fprintf(yyout, "%s:\n", end_label);
        pop_break_label();
    }
    
    else if(tree->id_type==BREAK_STMNT){
        const char* label = top_break_label();
        if(label == NULL){
            printf("ERROR: BREAK statement is not valid. (the BREAK keyword is not used inside any loop)\n");
            return 0;
        }
        else{
            const char* asm_code = "\tj %s\n";
            fprintf(yyout, asm_code, label);
        }
    }
    // else if(tree->id_type==CONTINUE_STMNT)    return 2;

    return 0;
}


int compile_stmt_list(node* tree){

    if(tree == nullptr) return 0;
    if(tree->id_type != STATEMENT_LIST) {printf("ERROR: trying to execute which is not STATEMENT_LIST\n"); return 0;}

    tree = tree->child;
    if(tree == nullptr) return 0;
    if(tree->id_type != STATEMENT) {printf("ERROR: trying to execute which is not STATEMENT\n"); return 0;}

    while(tree){
        int loopStatus = compile_stmt(tree->child);
        if(loopStatus) return loopStatus;
        tree = tree->next;
    }

    return 0;
}


void compile_declareVar(node* tree, _DATA_TYPES_ varDataType){
    if(tree == nullptr) return;
    if(tree->id_type != VARIABLE) {printf("ERROR: trying to declare which is not VARIABLE\n"); return;}

    switch(varDataType){
        case _INT_:
            if(tree->child != nullptr){
                // int array_length = evaluate_expr(tree->child);
                int array_length = tree->child->val;
                const char* asm_var_declr = "\t.globl	%s\n\t.align	2\n\t.type	%s, @object\n\t.size	%s, %d\n%s:\n\t.space	%d\n";
                fprintf(yyout, asm_var_declr, tree->name, tree->name, tree->name, 4*array_length, tree->name, 4*array_length);
            }
            else {
                const char* asm_var_declr = "\t.globl	%s\n\t.align	2\n\t.type	%s, @object\n\t.size	%s, 4\n%s:\n\t.space	4\n";
                fprintf(yyout, asm_var_declr, tree->name, tree->name, tree->name, tree->name);
            }
            break;
        
        case _BOOLEAN_:
            if(tree->child != nullptr){
                int array_length = tree->child->val;
                const char* asm_var_declr = "\t.globl	%s\n\t.align	2\n\t.type	%s, @object\n\t.size	%s, %d\n%s:\n\t.space	%d\n";
                fprintf(yyout, asm_var_declr, tree->name, tree->name, tree->name, 4*array_length, tree->name, 4*array_length);
            }
            else {
                const char* asm_var_declr = "\t.globl	%s\n\t.align	2\n\t.type	%s, @object\n\t.size	%s, 4\n%s:\n\t.space	4\n";
                fprintf(yyout, asm_var_declr, tree->name);
            }
            break;
        
        default:
            printf("ERROR: trying to execute of unkonwn data type\n"); 
    }
    
}


void compile_Ldecl_list(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != Ldecl_list) {printf("ERROR: trying to execute which is not Ldecl_list\n"); return;}

    tree = tree->child;
    _DATA_TYPES_ varDataType = static_cast<_DATA_TYPES_>(tree->val);
    tree = tree->next;
    while(tree){
        compile_declareVar(tree, varDataType);
        tree = tree->next;
    }
}


void compile_Decl(node* tree){
    if(tree == nullptr) return;
    if(tree->id_type != DECLERATION) {printf("ERROR: trying to execute which is not decleration\n"); return;}

    tree = tree->child;
    if(tree != nullptr) {
        const char* asm_global_var_section_declaration = "\t.text\n\t.section	.bss,\"aw\",@nobits\n";
        fprintf(yyout, "%s", asm_global_var_section_declaration);
    }
    while(tree){
        compile_Ldecl_list(tree);
        tree = tree->next;
    }
}


void compile_tree(node* tree){
    if(tree == nullptr) return;

    const char* start_asm_code = "\t.file	1 \"s1.c\"\n\t.section .mdebug.abi32\n\t.previous\n\t.nan	legacy\n\t.module	fp=32\n\t.module	nooddspreg\n\t.module	arch=r2000\n\t.abicalls\n";
    fprintf(yyout, "%s", start_asm_code);

    compile_Decl(tree->child);

    const char* middle_asm_code = "\t.rdata\n\t.align	2\n$LC0:\n\t.ascii	\"%d\\000\"\n\t.align	2\n$LC1:\n\t.ascii	\"%d\\012\\000\"\n\t.text\n\t.align	2\n\t.globl	main\n\t.set	nomips16\n\t.set	nomicromips\n\t.ent	main\n\t.type	main, @function\nmain:\n\t.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8\n\t.mask	0xc0000000,-4\n\t.fmask	0x00000000,0\n\t.set	noreorder\n\t.cpload	$25\n\t.set	reorder\n\taddiu	$sp,$sp,-32\n\tsw	$31,28($sp)\n\tsw	$fp,24($sp)\n\tmove	$fp,$sp\n\t.cprestore	16\n";
    fprintf(yyout, "%s", middle_asm_code);

    if(tree->child){
        compile_stmt_list(tree->child->next);
    }

    const char* end_asm_code = "\tmove	$sp,$fp\n\tlw	$31,28($sp)\n\tlw	$fp,24($sp)\n\taddiu	$sp,$sp,32\n\tj	$31\n\t.end	main\n\t.size	main, .-main\n\t.ident	\"GCC: (Ubuntu 12.3.0-17ubuntu1) 12.3.0\"\n\t.section	.note.GNU-stack,\"\",@progbits\n";
    fprintf(yyout, "%s", end_asm_code);

    


}





#endif
