#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct _DynamicArray
{
    size_t count;
    void **elements;
} DynamicArray;

/**
 * @brief Sets member variables of DynamicArray.
 * @param array Pointer to DynamicArray. This should be already allocated structure.
 * @param count Count of needed elements.
 */
void dynamic_array_init(DynamicArray *array, size_t count);

/**
 * @brief Inserts new element to array.
 * @param array Pointer to DynamicArray.
 * @param element Element to insert.
 * @return True if element was inserted, otherwise return false.
 */
bool dynamic_array_push(DynamicArray *array, void *element);

/**
 * @brief Removes element by index.
 * @param array Pointer to DynamicArray.
 * @param index Index of element to remove.
 * @return True if element removal was successful, otherwise return false.
 */
bool dynamic_array_pop(DynamicArray *array, size_t index);

/**
 * @brief Gets element at specific index.
 * @param array Pointer to DynamicArray.
 * @param index Index to set.
 */
void *dynamic_array_get(DynamicArray *array, size_t index);

/**
 * @brief Sets element at specific index.
 * @param array Pointer to DynamicArray.
 * @param index Index to set.
 * @param element Pointer to element to set.
 */
bool dynamic_array_set(DynamicArray *array, size_t index, void *element);


/**
 * @brief Deallocated heap allocated member variables of DynamicArray.
 * @param array Pointer to DynamicArray.
 */
void dynamic_array_destroy(DynamicArray *array);

#endif
