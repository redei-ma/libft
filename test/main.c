#include "test.h"

int	main(void)
{
	test_type();
	test_str();
	test_mem();
	test_alloc();
	test_lst();
	test_print();
	test_misc();
	test_null();
	printf("\n%d passed", passes());
	if (failures() == 0)
		return (printf(", 0 failed\n"), 0);
	return (printf(", %d FAILED\n", failures()), 1);
}
