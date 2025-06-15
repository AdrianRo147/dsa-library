#ifndef QUEUE_TESTS_H
#define QUEUE_TESTS_H

extern void test_queue_init_success(void);
extern void test_queue_init_null_queue(void);
extern void test_queue_init_null_data(void);
extern void test_queue_insert_success(void);
extern void test_queue_insert_multiple_elements(void);
extern void test_queue_insert_null_queue(void);
extern void test_queue_insert_null_data(void);
extern void test_queue_remove_success(void);
extern void test_queue_remove_until_empty(void);
extern void test_queue_remove_empty_queue(void);
extern void test_queue_remove_null_queue(void);
extern void test_queue_is_empty_true(void);
extern void test_queue_is_empty_false(void);
extern void test_queue_is_empty_null_queue(void);
extern void test_queue_front_success(void);
extern void test_queue_front_single_element(void);
extern void test_queue_front_empty_queue(void);
extern void test_queue_front_null_queue(void);
extern void test_queue_destroy_success(void);
extern void test_queue_destroy_empty_queue(void);
extern void test_queue_destroy_null_queue(void);
extern void test_queue_with_strings(void);
extern void test_queue_fifo_behavior(void);
extern void register_queue_tests(void);

#endif
