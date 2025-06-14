#include "node.h"

#include <stddef.h>
#include <stdlib.h>

 /**
 * @brief Initialize Node.
 * @param node Pointer to heap allocated node.
 * @param data Pointer to heap allocated data to set. If there's no data to set, use NULL.
 */
bool node_init(Node * const node, void * const data)
{
    if (node == NULL)
        return false;

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return true;
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
    new_node->prev = node;
    new_node->next = NULL;

    node->next = new_node;

    return new_node;
}

/**
 * @brief Removes target node using pointer.
 * @param node Pointer to first node.
 * @param target Pointer to target node to remove.
 */
Node *node_pop(Node * const node, const Node * const target)
{
    if (node == NULL || target == NULL)
        return NULL;

    if (node == target)
    {
        free(node->data);
        node->data = NULL;

        if (node->next != NULL)
            node->next->prev = NULL;

        if (node->prev != NULL)
        {
            if (node->next != NULL)
                node->prev->next = node->next;
            else
                node->prev->next = NULL;
        }

        return node;
    }

    Node *current = node;

    while (current != NULL)
    {
        Node *next = current->next;

        if (current == target)
        {
            Node *prev = current->prev;

            if (current->data != NULL)
            {
                free(current->data);
                current->data = NULL;
            }

            if (prev != NULL)
                prev->next = next;

            if (next != NULL)
                next->prev = prev;

            free(current);
            current = NULL;

            return prev;
        }

        current = next;
    }

    return NULL;
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
bool node_destroy(Node * const node)
{
    if (node == NULL)
        return false;

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

    return true;
}
