#include "linked_list.h"

#include <stdlib.h>

#include "../node/node.h"

/**
 * @brief Initializes Linked List.
 * @param list Pointer to heap allocated linked list.
 */
bool linked_list_init(LinkedList * const list, void * const data)
{
    if (list == NULL)
        return false;

    if (data == NULL)
    {
        list->size = 0;
        list->start = NULL;
        list->end = NULL;
    }
    else
    {
        list->start = (Node*)malloc(sizeof(Node));

        if (!node_init(list->start, data))
        {
            free(list->start);
            list->start = NULL;
            list->end = list->start;
            list->size = 0;

            return true;
        }

        list->end = list->start;
        list->size = 1;
    }

    return true;
}

/**
 * @brief Inserts new element into linked list.
 * @param list Pointer to linked list where new element has to be inserted.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
bool linked_list_insert(LinkedList * const list, void * const data)
{
    if (list == NULL || data == NULL)
        return false;

    if (list->end == NULL && list->start == NULL && list->size == 0)
    {
        list->start = (Node*)malloc(sizeof(Node));

        if (!node_init(list->start, data))
        {
            free(list->start);
            return false;
        }

        list->end = list->start;
        list->size = 1;

        return true;
    }

    if (list->end == NULL)
        return false;

    Node *new_node = node_push(list->end, data);

    if (new_node == NULL)
        return false;

    list->size++;
    list->end = new_node;

    return true;
}

/**
 * @brief Removes element from linked list.
 * @param list Pointer to linked list.
 * @param target Pointer to target node to remove.
 * @return True on success, otherwise return false.
 */
bool linked_list_remove(LinkedList * const list, Node * const target)
{
    if (list == NULL || target == NULL)
        return false;

    if (list->start == NULL)
        return false;

    Node *previous = node_pop(list->start, target);

    if (previous == NULL)
        return false;

    if (previous->next == NULL)
    {
        list->end = previous;
    }

    if (list->start->data == NULL && list->start->next != NULL)
    {
        if (previous->prev == NULL)
        {
            Node *next = previous->next;
            free(previous);
            list->start = next;
            list->size--;
            return true;
        }
        else
        {
            free(list->start);
            list->start = previous->next;
            list->size--;
            return true;
        }
    }

    if (list->size == 1 && previous->next == NULL && previous->prev == NULL)
    {
        free(previous);
        list->start = NULL;
        list->end = NULL;
    }

    list->size--;

    return true;
}

/**
 * @brief Destroys linked list.
 * @param list Pointer to list.
 * @return True on success, otherwise return false.
 */
bool linked_list_destroy(LinkedList * const list)
{
    if (list == NULL)
        return false;

    if (list->size == 0)
        return true;

    if (!node_destroy(list->start))
        return false;

    list->start = NULL;
    list->end = NULL;
    list->size = 0;

    return true;
}
