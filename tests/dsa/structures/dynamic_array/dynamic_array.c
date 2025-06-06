#include "dynamic_array.h"

#include <dsa/structures/dynamic_array/dynamic_array.h>

#include <CUnit/CUnit.h>
#include <stdbool.h>

static int test_int1 = 42;
static int test_int2 = 100;
static int test_int3 = 200;
static char test_str1[] = "Hello";
static char test_str2[] = "World";

void test_dynamic_array_init_normal(void)
{
    DynamicArray array;

    dynamic_array_init(&array, 5);

    CU_ASSERT_EQUAL(array.count, 5);
    CU_ASSERT_PTR_NOT_NULL(array.elements);

    for (size_t i = 0; i < array.count; i++)
    {
        CU_ASSERT_PTR_NULL(array.elements[i]);
    }

    dynamic_array_destroy(&array);
}

void test_dynamic_array_init_zero_count(void)
{
    DynamicArray array;

    dynamic_array_init(&array, 0);

    CU_ASSERT_EQUAL(array.count, 0);
    CU_ASSERT_PTR_NOT_NULL(array.elements);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_init_large_count(void)
{
    DynamicArray array;

    dynamic_array_init(&array, 1000);

    CU_ASSERT_EQUAL(array.count, 1000);
    CU_ASSERT_PTR_NOT_NULL(array.elements);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_push_to_empty(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    bool result = dynamic_array_push(&array, &test_int1);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(array.count, 1);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int1);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_push_multiple_elements(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    bool result1 = dynamic_array_push(&array, &test_int1);
    bool result2 = dynamic_array_push(&array, &test_int2);
    bool result3 = dynamic_array_push(&array, &test_str1);

    CU_ASSERT_TRUE(result1);
    CU_ASSERT_TRUE(result2);
    CU_ASSERT_TRUE(result3);
    CU_ASSERT_EQUAL(array.count, 3);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int1);
    CU_ASSERT_PTR_EQUAL(array.elements[1], &test_int2);
    CU_ASSERT_PTR_EQUAL(array.elements[2], &test_str1);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_push_null_element(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    bool result = dynamic_array_push(&array, NULL);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(array.count, 1);
    CU_ASSERT_PTR_NULL(array.elements[0]);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_pop_valid_index(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);
    dynamic_array_push(&array, &test_int2);
    dynamic_array_push(&array, &test_int3);

    bool result = dynamic_array_pop(&array, 1);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(array.count, 2);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int1);
    CU_ASSERT_PTR_EQUAL(array.elements[1], &test_int3);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_pop_first_element(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);
    dynamic_array_push(&array, &test_int2);

    bool result = dynamic_array_pop(&array, 0);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(array.count, 1);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int2);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_pop_last_element(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);
    dynamic_array_push(&array, &test_int2);

    bool result = dynamic_array_pop(&array, 1);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(array.count, 1);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int1);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_pop_invalid_index(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);

    bool result = dynamic_array_pop(&array, 5);

    CU_ASSERT_FALSE(result);
    CU_ASSERT_EQUAL(array.count, 1);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_pop_empty_array(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    bool result = dynamic_array_pop(&array, 0);

    CU_ASSERT_FALSE(result);
    CU_ASSERT_EQUAL(array.count, 0);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_get_valid_index(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);
    dynamic_array_push(&array, &test_str1);

    void *result1 = dynamic_array_get(&array, 0);
    void *result2 = dynamic_array_get(&array, 1);

    CU_ASSERT_PTR_EQUAL(result1, &test_int1);
    CU_ASSERT_PTR_EQUAL(result2, &test_str1);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_get_invalid_index(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);

    void *result = dynamic_array_get(&array, 5);

    CU_ASSERT_PTR_NULL(result);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_get_empty_array(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    void *result = dynamic_array_get(&array, 0);

    CU_ASSERT_PTR_NULL(result);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_set_valid_index(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 3);

    bool result1 = dynamic_array_set(&array, 0, &test_int1);
    bool result2 = dynamic_array_set(&array, 2, &test_str1);

    CU_ASSERT_TRUE(result1);
    CU_ASSERT_TRUE(result2);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int1);
    CU_ASSERT_PTR_NULL(array.elements[1]);
    CU_ASSERT_PTR_EQUAL(array.elements[2], &test_str1);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_set_invalid_index(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 2);

    bool result = dynamic_array_set(&array, 5, &test_int1);

    CU_ASSERT_FALSE(result);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_set_replace_existing(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 2);

    dynamic_array_set(&array, 0, &test_int1);
    bool result = dynamic_array_set(&array, 0, &test_int2);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_EQUAL(array.elements[0], &test_int2);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_set_null_element(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 2);

    dynamic_array_set(&array, 0, &test_int1);
    bool result = dynamic_array_set(&array, 0, NULL);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_NULL(array.elements[0]);

    dynamic_array_destroy(&array);
}

void test_dynamic_array_destroy(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 5);

    dynamic_array_destroy(&array);

    CU_ASSERT_EQUAL(array.count, 0);
    CU_ASSERT_PTR_NULL(array.elements);
}

void test_dynamic_array_integration_scenario(void)
{
    DynamicArray array;
    dynamic_array_init(&array, 0);

    dynamic_array_push(&array, &test_int1);
    dynamic_array_push(&array, &test_int2);
    dynamic_array_push(&array, &test_str1);
    CU_ASSERT_EQUAL(array.count, 3);

    dynamic_array_pop(&array, 1);
    CU_ASSERT_EQUAL(array.count, 2);
    CU_ASSERT_PTR_EQUAL(dynamic_array_get(&array, 0), &test_int1);
    CU_ASSERT_PTR_EQUAL(dynamic_array_get(&array, 1), &test_str1);

    dynamic_array_push(&array, &test_str2);
    CU_ASSERT_EQUAL(array.count, 3);
    CU_ASSERT_PTR_EQUAL(dynamic_array_get(&array, 2), &test_str2);

    dynamic_array_destroy(&array);
}

void register_dynamic_array_tests(void)
{
    CU_pSuite suite = CU_add_suite("DynamicArraySuite", 0, 0);
    if (suite == NULL) return;

    CU_add_test(suite, "test_dynamic_array_init_normal", test_dynamic_array_init_normal);
    CU_add_test(suite, "test_dynamic_array_init_zero_count", test_dynamic_array_init_zero_count);
    CU_add_test(suite, "test_dynamic_array_init_large_count", test_dynamic_array_init_large_count);
    CU_add_test(suite, "test_dynamic_array_push_to_empty", test_dynamic_array_push_to_empty);
    CU_add_test(suite, "test_dynamic_array_push_multiple_elements", test_dynamic_array_push_multiple_elements);
    CU_add_test(suite, "test_dynamic_array_push_null_element", test_dynamic_array_push_null_element);
    CU_add_test(suite, "test_dynamic_array_pop_valid_index", test_dynamic_array_pop_valid_index);
    CU_add_test(suite, "test_dynamic_array_pop_first_element", test_dynamic_array_pop_first_element);
    CU_add_test(suite, "test_dynamic_array_pop_last_element", test_dynamic_array_pop_last_element);
    CU_add_test(suite, "test_dynamic_array_pop_invalid_index", test_dynamic_array_pop_invalid_index);
    CU_add_test(suite, "test_dynamic_array_pop_empty_array", test_dynamic_array_pop_empty_array);
    CU_add_test(suite, "test_dynamic_array_get_valid_index", test_dynamic_array_get_valid_index);
    CU_add_test(suite, "test_dynamic_array_get_invalid_index", test_dynamic_array_get_invalid_index);
    CU_add_test(suite, "test_dynamic_array_get_empty_array", test_dynamic_array_get_empty_array);
    CU_add_test(suite, "test_dynamic_array_set_valid_index", test_dynamic_array_set_valid_index);
    CU_add_test(suite, "test_dynamic_array_set_invalid_index", test_dynamic_array_set_invalid_index);
    CU_add_test(suite, "test_dynamic_array_set_replace_existing", test_dynamic_array_set_replace_existing);
    CU_add_test(suite, "test_dynamic_array_set_null_element", test_dynamic_array_set_null_element);
    CU_add_test(suite, "test_dynamic_array_destroy", test_dynamic_array_destroy);
    CU_add_test(suite, "test_dynamic_array_integration_scenario", test_dynamic_array_integration_scenario);
}
