#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

extern void pibonacci(int a[], int n);
void test_func1();
void test_func2();

int main() {
	CU_pSuite test_suite;
	
	CU_initialize_registry();
	test_suite = CU_add_suite("TestSuite", NULL, NULL);
	CU_add_test(test_suite, "test1", test_func1);
	CU_add_test(test_suite, "test2", test_func2);
	CU_console_run_tests();
	CU_cleanup_registry();
}

void test_func1() {
	int a[] = {0, 0, 0};
	pibonacci(a, 3);
	CU_ASSERT (a[0] == 1);
	CU_ASSERT (a[1] == 2);
	CU_ASSERT (a[2] == 3);
}

void test_func2() {
	int a[] = {0, 0, 0, 0, 0};
	pibonacci(a, 5);
	CU_ASSERT (a[0] == 1);
	CU_ASSERT (a[1] == 2);
	CU_ASSERT (a[2] == 3);
	CU_ASSERT (a[3] == 5);
	CU_ASSERT (a[4] == 8);
}

void pibonacci(int a[], int n){
	int i;
	a[0] = 1; a[1] = 2;
	for (i = 2; i < n; i++)
	a[i] = a[i-1] + a[i-2];
}

