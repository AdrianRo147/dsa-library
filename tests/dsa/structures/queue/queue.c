#include "queue.h"

#include <dsa/structures/queue/queue.h>

#include <stdlib.h>
#include <CUnit/CUnit.h>

void test_queue_init_success(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;

    Queue *queue = (Queue*)malloc(sizeof(Queue));
    bool result = queue_init(queue, test_data);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_NOT_NULL(queue->list);
    CU_ASSERT_FALSE(queue_is_empty(queue));
    
    queue_destroy(queue);
}

void test_queue_init_null_queue(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;
    
    bool result = queue_init(NULL, test_data);
    
    CU_ASSERT_FALSE(result);
    
    free(test_data);
}

void test_queue_init_null_data(void)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    bool result = queue_init(queue, NULL);
    
    CU_ASSERT_TRUE(result);
    
    queue_destroy(queue);
}

void test_queue_insert_success(void)
{
    int *init_data = (int*)malloc(sizeof(int));
    int *insert_data = (int*)malloc(sizeof(int));

    *init_data = 1;
    *insert_data = 2;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue_init(queue, init_data);

    bool result = queue_insert(queue, insert_data);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_FALSE(queue_is_empty(queue));
    
    queue_destroy(queue);
}

void test_queue_insert_multiple_elements(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    int *test_data2 = (int*)malloc(sizeof(int));
    int *test_data3 = (int*)malloc(sizeof(int));

    *test_data1 = 1;
    *test_data2 = 2;
    *test_data3 = 3;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue_init(queue, test_data1);
    bool result1 = queue_insert(queue, test_data2);
    bool result2 = queue_insert(queue, test_data3);
    
    CU_ASSERT_TRUE(result1);
    CU_ASSERT_TRUE(result2);
    
    int *front = (int*)queue_front(queue);
    CU_ASSERT_PTR_NOT_NULL(front);
    CU_ASSERT_EQUAL(*front, 1);
    
    queue_destroy(queue);
}

void test_queue_insert_null_queue(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;
    
    bool result = queue_insert(NULL, test_data);
    
    CU_ASSERT_FALSE(result);
    
    free(test_data);
}

void test_queue_insert_null_data(void)
{
    int *init_data = (int*)malloc(sizeof(int));
    *init_data = 1;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue_init(queue, init_data);
    bool result = queue_insert(queue, NULL);
    
    CU_ASSERT_FALSE(result);
    
    queue_destroy(queue);
}

void test_queue_remove_success(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    int *test_data2 = (int*)malloc(sizeof(int));

    *test_data1 = 1;
    *test_data2 = 2;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data1);
    queue_insert(queue, test_data2);
    
    bool result = queue_remove(queue);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_FALSE(queue_is_empty(queue));
    
    int *front = (int*)queue_front(queue);
    CU_ASSERT_PTR_NOT_NULL(front);
    CU_ASSERT_EQUAL(*front, 2);
    
    queue_destroy(queue);
}

void test_queue_remove_until_empty(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    int *test_data2 = (int*)malloc(sizeof(int));

    *test_data1 = 1;
    *test_data2 = 2;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data1);
    queue_insert(queue, test_data2);
    
    bool result1 = queue_remove(queue);
    bool result2 = queue_remove(queue);
    
    CU_ASSERT_TRUE(result1);
    CU_ASSERT_TRUE(result2);
    CU_ASSERT_TRUE(queue_is_empty(queue));
    
    queue_destroy(queue);
}

void test_queue_remove_empty_queue(void)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->list = NULL;
    
    bool result = queue_remove(queue);
    
    CU_ASSERT_FALSE(result);

    free(queue);
}

void test_queue_remove_null_queue(void)
{
    bool result = queue_remove(NULL);
    
    CU_ASSERT_FALSE(result);
}

void test_queue_is_empty_true(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data);
    queue_remove(queue);
    
    bool result = queue_is_empty(queue);
    
    CU_ASSERT_TRUE(result);
    
    queue_destroy(queue);
}

void test_queue_is_empty_false(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data);
    
    bool result = queue_is_empty(queue);
    
    CU_ASSERT_FALSE(result);
    
    queue_destroy(queue);
}

void test_queue_is_empty_null_queue(void)
{
    bool result = queue_is_empty(NULL);
    
    CU_ASSERT_FALSE(result);
}

void test_queue_front_success(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    int *test_data2 = (int*)malloc(sizeof(int));

    *test_data1 = 100;
    *test_data2 = 200;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data1);
    queue_insert(queue, test_data2);
    
    int *front = (int*)queue_front(queue);
    
    CU_ASSERT_PTR_NOT_NULL(front);
    CU_ASSERT_EQUAL(*front, 100);
    
    queue_destroy(queue);
}

void test_queue_front_single_element(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data);
    
    int *front = (int*)queue_front(queue);
    
    CU_ASSERT_PTR_NOT_NULL(front);
    CU_ASSERT_EQUAL(*front, 42);
    
    queue_destroy(queue);
}

void test_queue_front_empty_queue(void)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->list = NULL;
    
    void *front = queue_front(queue);
    
    CU_ASSERT_PTR_NULL(front);

    free(queue);
}

void test_queue_front_null_queue(void)
{
    void *front = queue_front(NULL);
    
    CU_ASSERT_PTR_NULL(front);
}

void test_queue_destroy_success(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    int *test_data2 = (int*)malloc(sizeof(int));

    *test_data1 = 1;
    *test_data2 = 2;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data1);
    queue_insert(queue, test_data2);
    
    bool result = queue_destroy(queue);
    
    CU_ASSERT_TRUE(result);
}

void test_queue_destroy_empty_queue(void)
{
    int *test_data = (int*)malloc(sizeof(int));
    *test_data = 42;
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue_init(queue, test_data);
    queue_remove(queue);
    
    bool result = queue_destroy(queue);
    
    CU_ASSERT_TRUE(result);
}

void test_queue_destroy_null_queue(void)
{
    bool result = queue_destroy(NULL);
    
    CU_ASSERT_FALSE(result);
}

void test_queue_with_strings(void)
{
    char *str1 = (char*)malloc(strlen("Hello") + 1);
    char *str2 = (char*)malloc(strlen("World") + 1);
    char *str3 = (char*)malloc(strlen("Test") + 1);
    
    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "Test");
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
   
    queue_init(queue, str1);
    queue_insert(queue, str2);
    queue_insert(queue, str3);
    
    char *front = (char*)queue_front(queue);
    CU_ASSERT_PTR_NOT_NULL(front);
    CU_ASSERT_STRING_EQUAL(front, "Hello");
    
    queue_remove(queue);
    front = (char*)queue_front(queue);
    CU_ASSERT_PTR_NOT_NULL(front);
    CU_ASSERT_STRING_EQUAL(front, "World");
    
    queue_destroy(queue);
}

void test_queue_fifo_behavior(void)
{
    int *test_data[5];
    
    for (int i = 0; i < 5; i++)
    {
        test_data[i] = (int*)malloc(sizeof(int));
        *test_data[i] = i + 10;
    }
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
   
    queue_init(queue, test_data[0]);
    
    for (int i = 1; i < 5; i++)
    {
        queue_insert(queue, test_data[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        int *front = (int*)queue_front(queue);
        CU_ASSERT_PTR_NOT_NULL(front);
        CU_ASSERT_EQUAL(*front, i + 10);
        queue_remove(queue);
    }
    
    CU_ASSERT_TRUE(queue_is_empty(queue));
    queue_destroy(queue);
}

void register_queue_tests(void)
{
    CU_pSuite suite = CU_add_suite("QueueSuite", 0, 0);

    if (suite == NULL) return;

    CU_add_test(suite, "test_queue_init_success", test_queue_init_success);
    CU_add_test(suite, "test_queue_init_null_queue", test_queue_init_null_queue);
    CU_add_test(suite, "test_queue_init_null_data", test_queue_init_null_data);
    CU_add_test(suite, "test_queue_insert_success", test_queue_insert_success);
    CU_add_test(suite, "test_queue_insert_multiple_elements", test_queue_insert_multiple_elements);
    CU_add_test(suite, "test_queue_insert_null_queue", test_queue_insert_null_queue);
    CU_add_test(suite, "test_queue_insert_null_data", test_queue_insert_null_data);
    CU_add_test(suite, "test_queue_remove_success", test_queue_remove_success);
    CU_add_test(suite, "test_queue_remove_until_empty", test_queue_remove_until_empty);
    CU_add_test(suite, "test_queue_remove_empty_queue", test_queue_remove_empty_queue);
    CU_add_test(suite, "test_queue_remove_null_queue", test_queue_remove_null_queue);
    CU_add_test(suite, "test_queue_is_empty_true", test_queue_is_empty_true);
    CU_add_test(suite, "test_queue_is_empty_false", test_queue_is_empty_false);
    CU_add_test(suite, "test_queue_is_empty_null_queue", test_queue_is_empty_null_queue);
    CU_add_test(suite, "test_queue_front_success", test_queue_front_success);
    CU_add_test(suite, "test_queue_front_single_element", test_queue_front_single_element);
    CU_add_test(suite, "test_queue_front_empty_queue", test_queue_front_empty_queue);
    CU_add_test(suite, "test_queue_front_null_queue", test_queue_front_null_queue);
    CU_add_test(suite, "test_queue_destroy_success", test_queue_destroy_success);
    CU_add_test(suite, "test_queue_destroy_empty_queue", test_queue_destroy_empty_queue);
    CU_add_test(suite, "test_queue_destroy_null_queue", test_queue_destroy_null_queue);
    CU_add_test(suite, "test_queue_with_strings", test_queue_with_strings);
    CU_add_test(suite, "test_queue_fifo_behavior", test_queue_fifo_behavior);
}
