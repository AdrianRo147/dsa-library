#include "queue.h"

#include <stdlib.h>

/**
 * @brief Initializes queue.
 * @param queue Pointer to queue.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
bool queue_init(Queue *queue, void *data)
{
    if (queue == NULL)
        return false;

    queue->list = (LinkedList*)malloc(sizeof(LinkedList));

    if (queue->list == NULL)
        return false;

    if (!linked_list_init(queue->list, data))
    {
        free(queue->list);
        return false;
    }

    return true;
}

/**
 * @brief Inserts new element to queue.
 * @param queue Pointer to queue.
 * @param data Pointer to heap allocated data.
 * @return True on success, otherwise return false.
 */
bool queue_insert(Queue *queue, void *data)
{
    if (queue == NULL)
        return false;

    if (queue->list == NULL)
        return false;

    return linked_list_insert(queue->list, data);
}

/**
 * @brief Removes front (oldest) element from queue.
 * @param queue Pointer to queue.
 * @return True on success, otherwise return false.
 */
bool queue_remove(Queue *queue)
{
    if (queue == NULL)
        return false;

    if (queue->list == NULL)
        return false;

    if (queue->list->size == 0 || queue->list->start == NULL || queue->list->end == NULL)
        return false;

    return linked_list_remove(queue->list, queue->list->start);
}

/**
 * @brief Finds out if queue is empty.
 * @param queue Pointer to queue.
 * @return True if queue is empty, otherwise return false.
 */
bool queue_is_empty(Queue *queue)
{
    if (queue == NULL)
        return false;

    if (queue->list == NULL)
        return false;

    return queue->list->start == 0;
}

/**
 * @brief Gets front (oldest) element of queue.
 * @param queue Pointer to queue.
 * @return Front (oldest) element or NULL if error occurred.
 */
void *queue_front(Queue *queue)
{
    if (queue == NULL)
        return NULL;

    if (queue->list == NULL)
        return NULL;

    if (queue->list->start == NULL)
        return NULL;

    return queue->list->start->data;
}

/**
 * @brief Destroys queue.
 * @param queue Pointer to queue.
 * @return True on success, otherwise return false.
 */
bool queue_destroy(Queue *queue)
{
    if (queue == NULL)
        return false;

    if (queue->list == NULL)
        return false;

    if (!linked_list_destroy(queue->list))
        return false;

    free(queue);

    return true;
}
