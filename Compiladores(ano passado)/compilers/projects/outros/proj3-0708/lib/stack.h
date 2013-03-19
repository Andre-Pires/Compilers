#ifndef _STACK_H_
#define _STACK_H_

/* stack_element_t */
typedef struct stack_element {
    void *object;
    struct stack_element *next;
} stack_element_t;

/* stacK_t */
typedef struct {
  int numElems;
  stack_element_t *first;
  stack_element_t *last;
} stacK_t;


/* stack_create - allocates memory for stacK_t and initiates the structure */
stacK_t* stack_create();

/* stack_destroy - frees all memory used by stack if it is empty */
int stack_destroy(stacK_t *stack);

/* stack_is_empty - returns 1 if stack empty, else returns 0 */
int stack_is_empty(stacK_t *stack);

/* stack_peek - returns a pointer to the stack first element */
void* stack_peek(stacK_t *stack);

/* stack_push - inserts a new element into the stack */
void stack_push(stacK_t *stack, void* object);

/* stack_bpush -inserts a new element at the bottom of the stack (tricky ^_^) */
void stack_bpush(stacK_t *stack, void *object);

/* stack_pop - removes the first element of the stack */
void* stack_pop(stacK_t *stack);

/* stack_getNumElems - returns the numbers elements that are in the stack */
int stack_getNumElems(stacK_t *stack);

/* stack_clean - remove all elements from the stack */
void stack_clean(stacK_t *stack);

/* debug */
void stack_print(stacK_t *stack, FILE *fp);

#endif
