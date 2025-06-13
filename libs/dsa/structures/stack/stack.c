#include "stack.h"

#include <stdlib.h>

/**
 * @brief Intializes stack.
 * @param stack Pointer to stack.
 * @param data Pointer to heap allocated data. Can be used NULL.
 * @return True on success, otherwise return false.
 */
bool stack_init(Stack *stack, void *data)
{
    if (stack == NULL)
        return false;

    stack->list = malloc(sizeof(LinkedList));

    if (stack->list == NULL)
        return false;

    if (!linked_list_init(stack->list, data))
    {
        free(stack->list);
        return false;
    }

    return true;
}

/**
 * @brief Inserts new element to stack.
 * @param stack Pointer to stack.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
bool stack_insert(Stack *stack, void *data)
{
    if (stack == NULL)
        return false;

    return linked_list_insert(stack->list, data);
}

/**
 * @brief Removes element from stack.
 * @param stack Pointer to stack.
 * @return True on success, otherwise return false.
 */
bool stack_remove(Stack *stack)
{
    if (stack == NULL)
        return false;

    if (stack->list == NULL)
        return false;

    return linked_list_remove(stack->list, stack->list->end);
}

/**
 * @brief Finds out if stack is empty.
 * @param stack Pointer to stack.
 * @return True if stack is empty, if not return false.
 */
bool stack_is_empty(Stack *stack)
{
    if (stack == NULL)
        return true;

    if (stack->list == NULL)
        return true;

    return stack->list->size == 0;
}

/**
 * @brief Gets top element of stack.
 * @param stack Pointer to stack.
 * @return Element as void* or NULL if error occurred.
 */
void *stack_top(Stack *stack)
{
    if (stack == NULL)
        return NULL;

    if (stack->list == NULL)
        return NULL;

    if (stack->list->end == NULL)
        return NULL;

    return stack->list->end->data;
}

/**
 * @brief Destroys stack.
 * @param stack Pointer to stack.
 * @return True on success, otherwise return false.
 */
bool stack_destroy(Stack *stack)
{
    if (stack == NULL)
        return false;

    if (!linked_list_destroy(stack->list))
        return false;

    free(stack->list);
    free(stack);

    return true;
}
