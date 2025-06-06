#ifndef DYNAMIC_ARRAY_TESTS_H
#define DYNAMIC_ARRAY_TESTS_H

extern void test_dynamic_array_init(void);
extern void test_dynamic_array_init_zero_count(void);
extern void test_dynamic_array_init_large_count(void);
extern void test_dynamic_array_push_to_empty(void);
extern void test_dynamic_array_push_multiple_elements(void);
extern void test_dynamic_array_push_null_element(void);
extern void test_dynamic_array_pop_valid_index(void);
extern void test_dynamic_array_pop_first_element(void);
extern void test_dynamic_array_pop_last_element(void);
extern void test_dynamic_array_pop_invalid_index(void);
extern void test_dynamic_array_pop_empty_array(void);
extern void test_dynamic_array_get_valid_index(void);
extern void test_dynamic_array_get_invalid_index(void);
extern void test_dynamic_array_get_empty_array(void);
extern void test_dynamic_array_set_valid_index(void);
extern void test_dynamic_array_set_invalid_index(void);
extern void test_dynamic_array_set_replace_existing(void);
extern void test_dynamic_array_set_null_element(void);
extern void test_dynamic_array_destroy(void);
extern void test_dynamic_array_integration_scenario(void);
extern void register_dynamic_array_tests(void);

#endif
