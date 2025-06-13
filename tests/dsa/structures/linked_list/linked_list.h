#ifndef LINKED_LIST_TESTS_H
#define LINKED_LIST_TESTS_H

extern void test_node_init_with_data(void);
extern void test_node_init_with_null_data(void);
extern void test_node_init_with_null_node(void);
extern void test_node_push_single(void);
extern void test_node_push_multiple(void);
extern void test_node_push_with_null_node(void);
extern void test_node_get_node_found(void);
extern void test_node_get_node_not_found(void);
extern void test_node_get_node_with_null_list(void);
extern void test_node_pop_first_node(void);
extern void test_node_pop_middle_node(void);
extern void test_node_pop_last_node(void);
extern void test_node_pop_single_node(void);
extern void test_node_destroy_single(void);
extern void test_node_destroy_multiple(void);
extern void test_node_destroy_with_null(void);
extern void test_linked_list_init_with_data(void);
extern void test_linked_list_init_with_null_data(void);
extern void test_linked_list_init_with_null_list(void);
extern void test_linked_list_insert_single(void);
extern void test_linked_list_insert_multiple(void);
extern void test_linked_list_insert_with_null_list(void);
extern void test_linked_list_remove_first_node(void);
extern void test_linked_list_remove_last_node(void);
extern void test_linked_list_remove_middle_node(void);
extern void test_linked_list_remove_single_node(void);
extern void test_linked_list_remove_with_null_list(void);
extern void test_linked_list_remove_with_null_target(void);
extern void test_linked_list_destroy_empty(void);
extern void test_linked_list_destroy_single(void);
extern void test_linked_list_destroy_multiple(void);
extern void test_linked_list_destroy_with_null(void);
extern void test_integration_complex_operations(void);
extern void test_integration_node_operations(void);
extern void register_linked_list_tests(void);

#endif
