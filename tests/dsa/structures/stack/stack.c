#include "stack.h"

#include <dsa/structures/stack/stack.h>

#include <CUnit/CUnit.h>
#include <stdbool.h>
#include <stdlib.h>

void test_stack_init_valid(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 10;

    bool result = stack_init(stack, test_data);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_NOT_NULL(stack->list);

    CU_ASSERT_TRUE(stack_destroy(stack));
}

void test_stack_init_null_data(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    bool result = stack_init(stack, NULL);

    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_NOT_NULL(stack->list);

    stack_destroy(stack);
}

void test_stack_init_null_stack(void) {
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 10;
    
    CU_ASSERT_FALSE(stack_init(NULL, test_data));
    
    free(test_data);
}

void test_stack_insert_valid(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    CU_ASSERT_TRUE(stack_init(stack, NULL));

    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    CU_ASSERT_TRUE(stack_insert(stack, test_data1));
    CU_ASSERT_TRUE(stack_insert(stack, test_data2));
    CU_ASSERT_TRUE(stack_insert(stack, test_data3));

    int *top = (int*)stack_top(stack);
    CU_ASSERT_PTR_NOT_NULL(top);
    CU_ASSERT_EQUAL(*top, 30);

    stack_destroy(stack);
}

void test_stack_insert_null_stack(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 10;

    bool result = stack_init(NULL, test_data);
    CU_ASSERT_FALSE(result);

    free(test_data);
}

void test_stack_insert_null_data(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);

    CU_ASSERT_FALSE(stack_insert(stack, NULL));

    stack_destroy(stack);
}

void test_stack_remove_valid(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);

    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    stack_insert(stack, test_data1);
    stack_insert(stack, test_data2);

    CU_ASSERT_TRUE(stack_remove(stack));

    int *top = (int*)stack_top(stack);
    CU_ASSERT_PTR_NOT_NULL(top);
    CU_ASSERT_EQUAL(*top, 10);

    stack_destroy(stack);
}

void test_stack_remove_empty_stack(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    CU_ASSERT_FALSE(stack_remove(stack));
    
    stack_destroy(stack);
}

void test_stack_remove_null_stack(void)
{
    CU_ASSERT_FALSE(stack_remove(NULL));
}

void test_stack_remove_single_element(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    int *test_data = (int*)malloc(sizeof(int));
	*test_data = 10;

    stack_insert(stack, test_data);
    
    CU_ASSERT_TRUE(stack_remove(stack));
    CU_ASSERT_TRUE(stack_is_empty(stack));
    
    stack_destroy(stack);
}

void test_stack_is_empty_true(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    CU_ASSERT_TRUE(stack_is_empty(stack));
    
    stack_destroy(stack);
}

void test_stack_is_empty_false(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    int *test_data = (int*)malloc(sizeof(int));
	*test_data = 10;

    stack_insert(stack, test_data);
    
    CU_ASSERT_FALSE(stack_is_empty(stack));
    
    stack_destroy(stack);
}

void test_stack_is_empty_null_stack(void)
{
    CU_ASSERT_TRUE(stack_is_empty(NULL));
}

void test_stack_top_valid(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    int *test_data1 = (int*)malloc(sizeof(int));
	*test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
	*test_data2 = 20;
    
    stack_insert(stack, test_data1);
    stack_insert(stack, test_data2);
    
    int* top = (int*)stack_top(stack);
    CU_ASSERT_PTR_NOT_NULL(top);
    CU_ASSERT_EQUAL(*top, 20);
    
    stack_destroy(stack);
}

void test_stack_top_empty_stack(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    CU_ASSERT_PTR_NULL(stack_top(stack));
    
    stack_destroy(stack);
}

void test_stack_top_null_stack(void)
{
    CU_ASSERT_PTR_NULL(stack_top(NULL));
}

void test_stack_top_string_data(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    char *test_string1 = (char*)malloc(6);
	strcpy(test_string1, "first");

    char *test_string2 = (char*)malloc(7);
	strcpy(test_string2, "second");
    
    stack_insert(stack, test_string1);
    stack_insert(stack, test_string2);
    
    char* top = (char*)stack_top(stack);
    CU_ASSERT_PTR_NOT_NULL(top);
    CU_ASSERT_STRING_EQUAL(top, "second");
    
    stack_destroy(stack);
}

void test_stack_destroy_valid(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;
    
    stack_insert(stack, test_data1);
    stack_insert(stack, test_data2);
    
    CU_ASSERT_TRUE(stack_destroy(stack));
}

void test_stack_destroy_empty_stack(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    CU_ASSERT_TRUE(stack_destroy(stack));
}

void test_stack_destroy_null_stack(void)
{
    CU_ASSERT_FALSE(stack_destroy(NULL));
}

void test_stack_lifo_behavior(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;
    
    stack_insert(stack, test_data1);
    stack_insert(stack, test_data2);
    stack_insert(stack, test_data3);
    
    int* top = (int*)stack_top(stack);
    CU_ASSERT_EQUAL(*top, 30);
    
    stack_remove(stack);
    top = (int*)stack_top(stack);
    CU_ASSERT_EQUAL(*top, 20);
    
    stack_remove(stack);
    top = (int*)stack_top(stack);
    CU_ASSERT_EQUAL(*top, 10);
    
    stack_remove(stack);
    CU_ASSERT_TRUE(stack_is_empty(stack));
    
    stack_destroy(stack);
}

void test_stack_multiple_operations(void)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack_init(stack, NULL);
    
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;
    
    stack_insert(stack, test_data1);
    stack_insert(stack, test_data2);
    
    int* top = (int*)stack_top(stack);
    CU_ASSERT_EQUAL(*top, 20);
    
    stack_remove(stack);
    stack_insert(stack, test_data3);
    
    top = (int*)stack_top(stack);
    CU_ASSERT_EQUAL(*top, 30);
    
    CU_ASSERT_FALSE(stack_is_empty(stack));
    
    stack_destroy(stack);
}

void register_stack_tests(void)
{
    CU_pSuite suite = CU_add_suite("StackSuite", 0, 0);

    if (suite == NULL) return;

    CU_add_test(suite, "test_stack_init_valid", test_stack_init_valid);
    CU_add_test(suite, "test_stack_init_null_data", test_stack_init_null_data);
    CU_add_test(suite, "test_stack_init_null_stack", test_stack_init_null_stack);
    CU_add_test(suite, "test_stack_insert_valid", test_stack_insert_valid);
    CU_add_test(suite, "test_stack_insert_null_stack", test_stack_insert_null_stack);
    CU_add_test(suite, "test_stack_insert_null_data", test_stack_insert_null_data);
    CU_add_test(suite, "test_stack_remove_valid", test_stack_remove_valid);
    CU_add_test(suite, "test_stack_remove_empty_stack", test_stack_remove_empty_stack);
    CU_add_test(suite, "test_stack_remove_null_stack", test_stack_remove_null_stack);
    CU_add_test(suite, "test_stack_remove_single_element", test_stack_remove_single_element);
    CU_add_test(suite, "test_stack_is_empty_true", test_stack_is_empty_true);
    CU_add_test(suite, "test_stack_is_empty_false", test_stack_is_empty_false);
    CU_add_test(suite, "test_stack_is_empty_null_stack", test_stack_is_empty_null_stack);
    CU_add_test(suite, "test_stack_top_valid", test_stack_top_valid);
    CU_add_test(suite, "test_stack_top_empty_stack", test_stack_top_empty_stack);
    CU_add_test(suite, "test_stack_top_null_stack", test_stack_top_null_stack);
    CU_add_test(suite, "test_stack_top_string_data", test_stack_top_string_data);
    CU_add_test(suite, "test_stack_destroy_valid", test_stack_destroy_valid);
    CU_add_test(suite, "test_stack_destroy_empty_stack", test_stack_destroy_empty_stack);
    CU_add_test(suite, "test_stack_destroy_null_stack", test_stack_destroy_null_stack);
    CU_add_test(suite, "test_stack_lifo_behavior", test_stack_lifo_behavior);
    CU_add_test(suite, "test_stack_multiple_operations", test_stack_multiple_operations);
}
