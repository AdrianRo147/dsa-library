#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "../linked_list/linked_list/linked_list.h"

typedef struct _Stack
{
    LinkedList *list;
} Stack;

/**
 * @brief Intializes stack.
 * @param stack Pointer to stack.
 * @param data Pointer to heap allocated data. Can be used NULL.
 * @return True on success, otherwise return false.
 */
bool stack_init(Stack *stack, void *data);

/**
 * @brief Inserts new element to stack.
 * @param stack Pointer to stack.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
bool stack_insert(Stack *stack, void *data);

/**
 * @brief Removes element from stack.
 * @param stack Pointer to stack.
 * @return True on success, otherwise return false.
 */
bool stack_remove(Stack *stack);

/**
 * @brief Finds out if stack is empty.
 * @param stack Pointer to stack.
 * @return True if stack is empty, if not return false.
 */
bool stack_is_empty(Stack *stack);

/**
 * @brief Destroys stack.
 * @param stack Pointer to stack.
 * @return True on success, otherwise return false.
 */
bool stack_destroy(Stack *stack);


#endif
