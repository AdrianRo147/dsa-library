#ifndef STACK_TESTS_H
#define STACK_TESTS_H

extern void test_stack_init_valid(void);
extern void test_stack_init_null_data(void);
extern void test_stack_init_null_stack(void);
extern void test_stack_insert_valid(void);
extern void test_stack_insert_null_stack(void);
extern void test_stack_insert_null_data(void);
extern void test_stack_remove_valid(void);
extern void test_stack_remove_empty_stack(void);
extern void test_stack_remove_null_stack(void);
extern void test_stack_remove_single_element(void);
extern void test_stack_is_empty_true(void);
extern void test_stack_is_empty_false(void);
extern void test_stack_is_empty_null_stack(void);
extern void test_stack_top_valid(void);
extern void test_stack_top_empty_stack(void);
extern void test_stack_top_null_stack(void);
extern void test_stack_top_string_data(void);
extern void test_stack_destroy_valid(void);
extern void test_stack_destroy_empty_stack(void);
extern void test_stack_destroy_null_stack(void);
extern void test_stack_lifo_behavior(void);
extern void test_stack_multiple_operations(void);
extern void register_stack_tests(void); 

#endif
