#include "node.h"

#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Initialize Node.
 * @param node Pointer to already allocated node.
 * @param data Pointer to data to set. If there's no data to set, use NULL.
 */
void node_init(Node * const node, void * const data)
{
    if (node == NULL)
        return;

    node->data = data;
    node->next = NULL;
}

/**
 * @brief Allocates new node and returns it.
 * @param node Pointer to last node. node->next should equal NULL.
 * @param data Pointer to data.
 * @return pointer to newly allocated node.
 */
Node *node_push(Node * const node, void * const data)
{
    if (node == NULL)
        return NULL;

    if (node->next != NULL)
        return NULL;

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    node->next = new_node;

    return new_node;
}

/**
 * @brief Removes target node using pointer.
 * @param node Pointer to first node.
 * @param target Pointer to target node to remove.
 */
void node_pop(Node * const node, const Node * const target)
{
    if (node == NULL || target == NULL)
        return;

    if (node == target)
    {
        free(node->data);
        node->data = NULL;
    }

    Node *previous = NULL;
    Node *current = node;

    while (current != NULL)
    {
        Node *next = current->next;

        if (current == target)
        {
            if (current->data != NULL)
            {
                free(current->data);
                current->data = NULL;
            }

            free(current);
            current = NULL;

            if (previous != NULL)
            {
                previous->next = next;
            }

            previous = current;
            current = next;
        }
    }
}

/**
 * @brief Gets node using data pointer.
 * @param node Pointer to first node.
 * @param data Data of node to find.
 * @return Pointer to node.
 */
Node *node_get_node(Node * const node, const void * const data)
{
    if (node == NULL)
        return NULL;

    Node *current = node;

    while (current != NULL)
    {
        Node *next = current->next;

        if (current->data == data)
            return current;

        current = next;
    }

    return NULL;
}

/**
 * @brief Destroys nodes.
 * @param node Pointer to first node.
 */
void node_destroy(Node * const node)
{
    if (node == NULL)
        return;

    Node *current = node;

    while (current != NULL)
    {
        Node *next = current->next;

        if (current->data != NULL)
        {
            free(current->data);
            current->data = NULL;
        }

        free(current);

        current = next;
    }
}
