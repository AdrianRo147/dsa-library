#include "../tests/dsa/structures/dynamic_array/dynamic_array.h"
#include "../tests/dsa/structures/linked_list/linked_list.h"
#include "../tests/dsa/structures/stack/stack.h"
#include "../tests/dsa/structures/queue/queue.h"

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    register_dynamic_array_tests();
    register_linked_list_tests();
    register_stack_tests();
    register_queue_tests();

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
