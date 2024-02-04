#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct arg_s - struct to hold variables
 * @line: read line fron input
 * @text_chunk: the stream of text from input FILE
 * @line_number: Keep track of current line in text_chunck
 * @tok_count: Number of tokens
 * @tokens: store tokens fron text_chunk
 * 
 * Description: holds variables implemented at various stage
 * of the program and makes them available globally
*/
typedef struct arg_s
{
        char *line;
        FILE *text_chunk;
        unsigned int line_number;
        int tok_count, stack_index;
        char **lines_tok;
        instruction_t *instruction;
        stack_t *head;
} arg_t;

extern arg_t *inputs;

void start_arguments(void);
void malloc_err(void);
void text_chunk_err(char *fileTitle);
void tokenize_line(void);
void get_text(char *fileTitle);
void free_input(arg_t *inputs);
void _get_opcodes(void);
void exec_opcode(stack_t *stack);
int isnumber(char *s);
int _atoi(char *s);
void close_input_file(void);
void free_head();
void free_tokens(void);
void free_inputs(void);
void free_stack(stack_t *head);
void free_all_memory();

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
