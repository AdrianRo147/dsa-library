#include "dynamic_array.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief Sets member variables of DynamicArray.
 * @param array Pointer to DynamicArray. This should be already allocated structure.
 * @param count Count of needed elements.
 */
void dynamic_array_init(DynamicArray *array, size_t count)
{
    array->count = count;
    array->elements = (void**)calloc(count, sizeof(void*));
}

/**
 * @brief Inserts new element to array.
 * @param array Pointer to DynamicArray.
 * @param element Element to insert.
 * @return True if element was inserted, otherwise return false.
 */
bool dynamic_array_push(DynamicArray *array, void *element)
{
    array->count++;
    void **new_array = (void**)malloc(array->count * sizeof(void*));

    if (new_array == NULL)
        return false;

    for (size_t i = 0; i < array->count - 1; i++)
    {
        *(new_array + i) = *(array->elements + i);
    }

    *(new_array + array->count - 1) = element;

    free(array->elements);
    array->elements = NULL;

    array->elements = new_array;

    return true;
}

/**
 * @brief Removes element by index.
 * @param array Pointer to DynamicArray.
 * @param index Index of element to remove.
 * @return True if element removal was successful, otherwise return false.
 */
bool dynamic_array_pop(DynamicArray *array, size_t index)
{
    if (index >= array->count)
        return false;

    array->count--;

    void **new_array = (void**)malloc(array->count * sizeof(void*));

    for (size_t i = 0; i <= array->count; i++)
    {
        if (i == index)
            continue;

        if (i < index)
            *(new_array + i) = *(array->elements + i);

        if (i > index)
            *(new_array + i - 1) = *(array->elements + i);
    }

    free(array->elements);
    array->elements = NULL;

    array->elements = new_array;

    return true;
}

/**
 * @brief Gets element at specific index.
 * @param array Pointer to DynamicArray.
 * @param index Index to set.
 */
void *dynamic_array_get(DynamicArray *array, size_t index)
{
    if (index >= array->count)
        return NULL;

    return *(array->elements + index);
}

/**
 * @brief Sets element at specific index.
 * @param array Pointer to DynamicArray.
 * @param index Index to set.
 * @param element Pointer to element to set.
 */
bool dynamic_array_set(DynamicArray *array, size_t index, void *element)
{
    if (index >= array->count)
        return false;

    *(array->elements + index) = element;

    return true;
}

/**
 * @brief Deallocated heap allocated member variables of DynamicArray.
 * @param array Pointer to DynamicArray.
 */
void dynamic_array_destroy(DynamicArray *array)
{
    array->count = 0;
    free(array->elements);
    array->elements = NULL;
}
