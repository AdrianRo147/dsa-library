#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

typedef struct _Node
{
    void *data;
    struct _Node *next;
} Node;

/**
 * @brief Initialize Node.
 * @param node Pointer to heap allocated node.
 * @param data Pointer to heap allocated data to set. If there's no data to set, use NULL.
 * @return True on success, otherwise return false.
 */
extern bool node_init(Node * const node, void * const data);

/**
 * @brief Allocates new node and returns it.
 * @param node Pointer to last node. node->next should equal NULL.
 * @param data Pointer to data.
 * @return pointer to newly allocated node.
 */
extern Node *node_push(Node * const node, void * const data);

/**
 * @brief Removes target node using pointer.
 * @param node Pointer to first node.
 * @param target Pointer to target node to remove.
 */
extern bool node_pop(Node * const node, const Node * const target);

/**
 * @brief Gets node using data pointer.
 * @param node Pointer to first node.
 * @param data Data of node to find.
 * @return Pointer to node.
 */
extern Node *node_get_node(Node * const node, const void * const data);

/**
 * @brief Destroys nodes.
 * @param node Pointer to first node.
 */
extern bool node_destroy(Node * const node);

#endif
