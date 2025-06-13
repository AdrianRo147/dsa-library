#include "linked_list.h"

#include <dsa/structures/linked_list/linked_list/linked_list.h>

#include <CUnit/CUnit.h>
#include <stdlib.h>
#include <string.h>

void test_node_init_with_data(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    Node *node = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(node);
    
    bool result = node_init(node, (void*)test_data1);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_EQUAL(node->data, (void*)test_data1);
    CU_ASSERT_PTR_NULL(node->next);
    CU_ASSERT_PTR_NULL(node->prev);
   
    free(test_data1);
    free(node);
}

void test_node_init_with_null_data(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    Node *node = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(node);
    
    bool result = node_init(node, NULL);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_PTR_NULL(node->data);
    CU_ASSERT_PTR_NULL(node->next);
    CU_ASSERT_PTR_NULL(node->prev);
   
    free(test_data1);
    free(node);
}

void test_node_init_with_null_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    bool result = node_init(NULL, (void*)test_data1);
    CU_ASSERT_FALSE(result);

    free(test_data1);
}

void test_node_push_single(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    Node *first = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    node_init(first, (void*)test_data1);
    
    Node *second = node_push(first, (void*)test_data2);
    
    CU_ASSERT_PTR_NOT_NULL(second);
    CU_ASSERT_PTR_EQUAL(first->next, second);
    CU_ASSERT_PTR_EQUAL(second->prev, first);
    CU_ASSERT_PTR_EQUAL(second->data, (void*)test_data2);
    CU_ASSERT_PTR_NULL(second->next);
    CU_ASSERT_PTR_NULL(first->prev);
    
    free(second);
    free(first);

    free(test_data1);
    free(test_data2);
}

void test_node_push_multiple(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    Node *first = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    node_init(first, (void*)test_data1);
    
    Node *second = node_push(first, (void*)test_data2);
    Node *third = node_push(second, (void*)test_data3);
    
    CU_ASSERT_PTR_NOT_NULL(second);
    CU_ASSERT_PTR_NOT_NULL(third);
    CU_ASSERT_PTR_EQUAL(first->next, second);
    CU_ASSERT_PTR_EQUAL(second->next, third);
    CU_ASSERT_PTR_EQUAL(second->prev, first);
    CU_ASSERT_PTR_EQUAL(third->prev, second);
    CU_ASSERT_PTR_NULL(first->prev);
    CU_ASSERT_PTR_NULL(third->next);
    
    free(third);
    free(second);
    free(first);

    free(test_data1);
    free(test_data2);
    free(test_data3);
}

void test_node_push_with_null_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    Node *result = node_push(NULL, (void*)test_data1);
    CU_ASSERT_PTR_NULL(result);

    free(test_data1);
}

void test_node_get_node_found(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    CU_ASSERT_PTR_NOT_NULL(second);
    
    node_init(first, (void*)test_data1);
    node_init(second, (void*)test_data2);
    first->next = second;
    second->prev = first;
    
    Node *found = node_get_node(first, (void*)test_data2);
    
    CU_ASSERT_PTR_EQUAL(found, second);
    
    free(second);
    free(first);

    free(test_data1);
    free(test_data2);
}

void test_node_get_node_not_found(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    Node *first = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    node_init(first, (void*)test_data1);
    
    Node *found = node_get_node(first, (void*)test_data2);
    
    CU_ASSERT_PTR_NULL(found);
    
    free(first);

    free(test_data1);
    free(test_data2);
}

void test_node_get_node_with_null_list(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    Node *found = node_get_node(NULL, (void*)test_data1);
    CU_ASSERT_PTR_NULL(found);

    free(test_data1);
}

void test_node_pop_first_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    CU_ASSERT_PTR_NOT_NULL(second);
    
    node_init(first, (void*)test_data1);
    node_init(second, (void*)test_data2);
    first->next = second;
    second->prev = first;
  
    Node *new_head = node_pop(first, first);

    CU_ASSERT_PTR_EQUAL(new_head, new_head);
    CU_ASSERT_PTR_NULL(second->prev);
   
    free(first);
    free(second);

    free(test_data2);
}

void test_node_pop_middle_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    Node *third = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    CU_ASSERT_PTR_NOT_NULL(second);
    CU_ASSERT_PTR_NOT_NULL(third);
    
    node_init(first, (void*)test_data1);
    node_init(second, (void*)test_data2);
    node_init(third, (void*)test_data3);
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    
    Node *new_head = node_pop(first, second);
    
    CU_ASSERT_PTR_EQUAL(new_head, first);
    CU_ASSERT_PTR_EQUAL(first->next, third);
    CU_ASSERT_PTR_EQUAL(third->prev, first);
    
    free(third);
    free(first);

    free(test_data1);
    free(test_data3);
}

void test_node_pop_last_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    CU_ASSERT_PTR_NOT_NULL(second);
    
    node_init(first, (void*)test_data1);
    node_init(second, (void*)test_data2);
    first->next = second;
    second->prev = first;
    
    Node *new_head = node_pop(first, second);
    
    CU_ASSERT_PTR_EQUAL(new_head, first);
    CU_ASSERT_PTR_NULL(first->next);
    
    free(first);

    free(test_data1);
}

void test_node_pop_single_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    Node *single = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(single);
    node_init(single, (void*)test_data1);
    
    Node *new_head = node_pop(single, single);
    
    CU_ASSERT_PTR_EQUAL(new_head, single);
    CU_ASSERT_PTR_NULL(new_head->data);

    free(new_head);
}

void test_node_destroy_single(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    Node *node = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(node);
    node_init(node, (void*)test_data1);
    
    bool result = node_destroy(node);
    
    CU_ASSERT_TRUE(result);
}

void test_node_destroy_multiple(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    Node *third = (Node*)malloc(sizeof(Node));
    CU_ASSERT_PTR_NOT_NULL(first);
    CU_ASSERT_PTR_NOT_NULL(second);
    CU_ASSERT_PTR_NOT_NULL(third);
    
    node_init(first, (void*)test_data1);
    node_init(second, (void*)test_data2);
    node_init(third, (void*)test_data3);
    first->next = second;
    second->next = third;
    
    bool result = node_destroy(first);
    
    CU_ASSERT_TRUE(result);
}

void test_node_destroy_with_null(void)
{
    bool result = node_destroy(NULL);
    CU_ASSERT_FALSE(result);
}

void test_linked_list_init_with_data(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    
    bool result = linked_list_init(list, (void*)test_data1);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_PTR_NOT_NULL(list->start);
    CU_ASSERT_PTR_EQUAL(list->start, list->end);
    CU_ASSERT_PTR_EQUAL(list->start->data, (void*)test_data1);
    CU_ASSERT_PTR_NULL(list->start->next);
    CU_ASSERT_PTR_NULL(list->start->prev);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_init_with_null_data(void)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    
    bool result = linked_list_init(list, NULL);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_PTR_NULL(list->start);
    CU_ASSERT_PTR_NULL(list->end);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_init_with_null_list(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    bool result = linked_list_init(NULL, (void*)test_data1);
    CU_ASSERT_FALSE(result);

    free(test_data1);
}

void test_linked_list_insert_single(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    
    bool result = linked_list_insert(list, (void*)test_data2);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_PTR_NOT_NULL(list->start);
    CU_ASSERT_PTR_NOT_NULL(list->end);
    CU_ASSERT_PTR_NOT_EQUAL(list->start, list->end);
    CU_ASSERT_PTR_EQUAL(list->start->next, list->end);
    CU_ASSERT_PTR_EQUAL(list->end->data, (void*)test_data2);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_insert_multiple(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    
    linked_list_insert(list, (void*)test_data2);
    bool result = linked_list_insert(list, (void*)test_data3);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_PTR_EQUAL(list->end->data, (void*)test_data3);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_insert_with_null_list(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    bool result = linked_list_insert(NULL, (void*)test_data1);
    CU_ASSERT_FALSE(result);

    free(test_data1);
}

void test_linked_list_remove_first_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    linked_list_insert(list, (void*)test_data2);
    
    Node *target = list->start;
    bool result = linked_list_remove(list, target);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_PTR_EQUAL(list->start, list->end);
    CU_ASSERT_PTR_EQUAL(list->start->data, (void*)test_data2);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_remove_last_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    linked_list_insert(list, (void*)test_data2);
    
    Node *target = list->end;
    bool result = linked_list_remove(list, target);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_PTR_EQUAL(list->start, list->end);
    CU_ASSERT_PTR_EQUAL(list->start->data, (void*)test_data1);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_remove_middle_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    linked_list_insert(list, (void*)test_data2);
    linked_list_insert(list, (void*)test_data3);
    
    Node *target = list->start->next;
    bool result = linked_list_remove(list, target);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_PTR_EQUAL(list->start->next, list->end);
    CU_ASSERT_PTR_EQUAL(list->start->data, (void*)test_data1);
    CU_ASSERT_PTR_EQUAL(list->end->data, (void*)test_data3);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_remove_single_node(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    
    Node *target = list->start;
    bool result = linked_list_remove(list, target);
    
    CU_ASSERT_TRUE(result);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_PTR_NULL(list->start);
    CU_ASSERT_PTR_NULL(list->end);
    
    free(list);
}

void test_linked_list_remove_with_null_list(void)
{
    bool result = linked_list_remove(NULL, NULL);
    CU_ASSERT_FALSE(result);
}

void test_linked_list_remove_with_null_target(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    
    bool result = linked_list_remove(list, NULL);
    
    CU_ASSERT_FALSE(result);
    
    linked_list_destroy(list);
    free(list);
}

void test_linked_list_destroy_empty(void)
{
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    
    bool result = linked_list_destroy(list);
    
    CU_ASSERT_TRUE(result);
    
    free(list);
}

void test_linked_list_destroy_single(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    
    bool result = linked_list_destroy(list);
    
    CU_ASSERT_TRUE(result);
    
    free(list);
}

void test_linked_list_destroy_multiple(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 20;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 30;

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    linked_list_init(list, (void*)test_data1);
    linked_list_insert(list, (void*)test_data2);
    linked_list_insert(list, (void*)test_data3);
    
    bool result = linked_list_destroy(list);
    
    CU_ASSERT_TRUE(result);
    
    free(list);
}

void test_linked_list_destroy_with_null(void)
{
    bool result = linked_list_destroy(NULL);
    CU_ASSERT_FALSE(result);
}

void test_integration_complex_operations(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 10;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 10;

    char *test_string1 = (char*)malloc(5);
    strcpy(test_string1, "Test");

    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    CU_ASSERT_PTR_NOT_NULL(list);
    
    linked_list_init(list, (void*)test_data1);
    CU_ASSERT_EQUAL(list->size, 1);
    
    linked_list_insert(list, (void*)test_data2);
    linked_list_insert(list, (void*)test_data3);
    CU_ASSERT_EQUAL(list->size, 3);
    
    Node *middle = list->start->next;
    linked_list_remove(list, middle);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_PTR_EQUAL(list->start->data, (void*)test_data1);
    CU_ASSERT_PTR_EQUAL(list->end->data, (void*)test_data3);
    
    linked_list_insert(list, test_string1);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_PTR_EQUAL(list->end->data, test_string1);
    
    linked_list_destroy(list);
    free(list);
}

void test_integration_node_operations(void)
{
    int *test_data1 = (int*)malloc(sizeof(int));
    *test_data1 = 10;

    int *test_data2 = (int*)malloc(sizeof(int));
    *test_data2 = 10;

    int *test_data3 = (int*)malloc(sizeof(int));
    *test_data3 = 10;

    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    Node *third = (Node*)malloc(sizeof(Node));
    
    node_init(first, (void*)test_data1);
    node_init(second, (void*)test_data2);
    node_init(third, (void*)test_data3);
    
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    
    Node *found = node_get_node(first, (void*)test_data2);
    CU_ASSERT_PTR_EQUAL(found, second);
    
    Node *new_head = node_pop(first, second);
    CU_ASSERT_PTR_EQUAL(new_head, first);
    CU_ASSERT_PTR_EQUAL(first->next, third);
    CU_ASSERT_PTR_EQUAL(third->prev, first);
    
    node_destroy(first);
}


void register_linked_list_tests(void)
{
    CU_pSuite suite = CU_add_suite("LinkedListSuite", 0, 0);

    if (suite == NULL) return;

    CU_add_test(suite, "test_node_init_with_data", test_node_init_with_data);
    CU_add_test(suite, "test_node_init_with_null_data", test_node_init_with_null_data);
    CU_add_test(suite, "test_node_init_with_null_node", test_node_init_with_null_node);
    CU_add_test(suite, "test_node_push_single", test_node_push_single);
    CU_add_test(suite, "test_node_push_multiple", test_node_push_multiple);
    CU_add_test(suite, "test_node_push_with_null_node", test_node_push_with_null_node);
    CU_add_test(suite, "test_node_get_node_found", test_node_get_node_found);
    CU_add_test(suite, "test_node_get_node_not_found", test_node_get_node_not_found);
    CU_add_test(suite, "test_node_get_node_with_null_list", test_node_get_node_with_null_list);
    CU_add_test(suite, "test_node_pop_first_node", test_node_pop_first_node);
    CU_add_test(suite, "test_node_pop_middle_node", test_node_pop_middle_node);
    CU_add_test(suite, "test_node_pop_last_node", test_node_pop_last_node);
    CU_add_test(suite, "test_node_pop_single_node", test_node_pop_single_node);
    CU_add_test(suite, "test_node_destroy_single", test_node_destroy_single);
    CU_add_test(suite, "test_node_destroy_multiple", test_node_destroy_multiple);
    CU_add_test(suite, "test_node_destroy_with_null", test_node_destroy_with_null);
    CU_add_test(suite, "test_linked_list_init_with_data", test_linked_list_init_with_data);
    CU_add_test(suite, "test_linked_list_init_with_null_data", test_linked_list_init_with_null_data);
    CU_add_test(suite, "test_linked_list_init_with_null_list", test_linked_list_init_with_null_list);
    CU_add_test(suite, "test_linked_list_insert_single", test_linked_list_insert_single);
    CU_add_test(suite, "test_linked_list_insert_multiple", test_linked_list_insert_multiple);
    CU_add_test(suite, "test_linked_list_insert_with_null_list", test_linked_list_insert_with_null_list);
    CU_add_test(suite, "test_linked_list_remove_first_node", test_linked_list_remove_first_node);
    CU_add_test(suite, "test_linked_list_remove_last_node", test_linked_list_remove_last_node);
    CU_add_test(suite, "test_linked_list_remove_middle_node", test_linked_list_remove_middle_node);
    CU_add_test(suite, "test_linked_list_remove_single_node", test_linked_list_remove_single_node);
    CU_add_test(suite, "test_linked_list_remove_with_null_list", test_linked_list_remove_with_null_list);
    CU_add_test(suite, "test_linked_list_remove_with_null_target", test_linked_list_remove_with_null_target);
    CU_add_test(suite, "test_linked_list_destroy_empty", test_linked_list_destroy_empty);
    CU_add_test(suite, "test_linked_list_destroy_single", test_linked_list_destroy_single);
    CU_add_test(suite, "test_linked_list_destroy_multiple", test_linked_list_destroy_multiple);
    CU_add_test(suite, "test_linked_list_destroy_with_null", test_linked_list_destroy_with_null);
}
