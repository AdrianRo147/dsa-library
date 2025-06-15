#ifndef QUEUE_H
#define QUEUE_H

#include "../linked_list/linked_list/linked_list.h"

#include <stdbool.h>

typedef struct _Queue
{
    LinkedList *list;
} Queue;

/**
 * @brief Initializes queue.
 * @param queue Pointer to queue.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
extern bool queue_init(Queue *queue, void *data);

/**
 * @brief Inserts new element to queue.
 * @param queue Pointer to queue.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
extern bool queue_insert(Queue *queue, void *data);

/**
 * @brief Removes front (oldest) element from queue.
 * @param queue Pointer to queue.
 * @return True on success, otherwise return false.
 */
extern bool queue_remove(Queue *queue);

/**
 * @brief Finds out if queue is empty.
 * @param queue Pointer to queue.
 * @return True if queue is empty, otherwise return false.
 */
extern bool queue_is_empty(Queue *queue);

/**
 * @brief Gets front (oldest) element of queue.
 * @param queue Pointer to queue.
 * @return Front (oldest) element or NULL if error occurred.
 */
extern void *queue_front(Queue *queue);

/**
 * @brief Destroys queue.
 * @param queue Pointer to queue.
 * @return True on success, otherwise return false.
 */
extern bool queue_destroy(Queue *queue);

#endif
