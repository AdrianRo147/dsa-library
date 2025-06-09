#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../node/node.h"

#include <stddef.h>
#include <stdbool.h>

typedef struct _LinkedList
{
    size_t size;
    Node *start;
    Node *end;
} LinkedList;

/**
 * @brief Initializes linked list.
 * @param list Pointer to heap allocated linked list.
 * @param data Pointer to heap allocated data. Can be used NULL.
 */
extern bool linked_list_init(LinkedList * const list, void * const data);

/**
 * @brief Inserts new element into linked list.
 * @param list Pointer to linked list where new element has to be inserted.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
extern bool linked_list_insert(LinkedList * const list, void * const data);

/**
 * @brief Removes element from linked list.
 * @param list Pointer to linked list.
 * @param target Pointer to target node to remove.
 * @return True on success, otherwise return false.
 */
extern bool linked_list_remove(LinkedList * const list, Node * const target);

/**
 * @brief Destroys linked list.
 * @param list Pointer to list.
 * @return True on success, otherwise return false.
 */
extern bool linked_list_destroy(LinkedList * const list);

#endif
