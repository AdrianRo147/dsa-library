#include "static_array.h"

#include <CUnit/CUnit.h>

void test_static_array_init()
{

}

void register_static_array_tests()
{
    CU_pSuite suite = CU_add_suite("StaticArraySuite", 0, 0);
    if (suite == NULL) return;

    CU_add_test(suite, "test_static_array_init", test_static_array_init);
}
