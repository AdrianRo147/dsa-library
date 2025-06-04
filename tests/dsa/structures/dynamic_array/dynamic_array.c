#include "dynamic_array.h"

#include <CUnit/CUnit.h>

void test_dynamic_array_init()
{

}

void register_dynamic_array_tests()
{
    CU_pSuite suite = CU_add_suite("DynamicArraySuite", 0, 0);
    if (suite == NULL) return;

    CU_add_test(suite, "test_dynamic_array_init", test_dynamic_array_init);
}
