/*
 ============================================================================
 Name        : array_test.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <CUnit/basic.h>
#include "array.h"

void test_length(){
	srand_time();
	int length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
	length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
	length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
	length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
	length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
	length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
	length = generate_length();
	CU_ASSERT_TRUE(length>ZERO);
}

void test_mean(){
	int a[] = {1};
	CU_ASSERT_EQUAL((int)mean(a,1),1);
	int b[] = {1,2};
	CU_ASSERT_EQUAL((int)mean(b,2),1);
	int c[] = {1,2,3};
	CU_ASSERT_EQUAL((int)mean(c,3),2);
	int d[] = {1,2,3,4};
	CU_ASSERT_EQUAL((int)mean(d,4),2);
	int e[] = {1,2,3,4,5};
	CU_ASSERT_EQUAL((int)mean(e,5),3);
	int f[] = {1,2,3,4,5,6};
	CU_ASSERT_EQUAL((int)mean(f,6),3);
}

void test_ordered_array(){
	int a[] = {1};
	CU_ASSERT_TRUE(ordered_array(a,1));
	int b[] = {1,2};
	CU_ASSERT_TRUE(ordered_array(b,2));
	int c[] = {2,1};
	CU_ASSERT_FALSE(ordered_array(c,2));
	int d[] = {1,1};
	CU_ASSERT_TRUE(ordered_array(d,2));
}

void test_bubble_sort(){
	int a[] = {1};
	bubble_sort(a,1);
	CU_ASSERT_TRUE(ordered_array(a,1));
	int b[] = {1,2};
	bubble_sort(b,2);
	CU_ASSERT_TRUE(ordered_array(b,2));
	int c[] = {1,1};
	bubble_sort(c,2);
	CU_ASSERT_TRUE(ordered_array(c,2));
	int d[] = {2,1};
	bubble_sort(d,2);
	CU_ASSERT_TRUE(ordered_array(d,2));
	int e[] = {2,1,4,3};
	bubble_sort(e,4);
	CU_ASSERT_TRUE(ordered_array(e,4));
}

void test_median(){
	int a[] ={1};
	CU_ASSERT_EQUAL(median(a,1),1);
	int b[] ={1,2};
	CU_ASSERT_EQUAL(median(b,2),2);
	int c[] ={1,2,3};
	CU_ASSERT_EQUAL(median(c,3),2);
	int d[] ={1,2,3,4};
	CU_ASSERT_EQUAL(median(d,4),3);
	int e[] ={1,2,3,4,5};
	CU_ASSERT_EQUAL(median(e,5),3);
	int f[] ={1,2,3,4,5,6};
	CU_ASSERT_EQUAL(median(f,6),4);
}

void test_linear_search(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	CU_ASSERT_FALSE(linear_search(a,9,0));
	CU_ASSERT_TRUE(linear_search(a,9,1));
	CU_ASSERT_TRUE(linear_search(a,9,5));
	CU_ASSERT_TRUE(linear_search(a,9,9));
	CU_ASSERT_FALSE(linear_search(a,9,10));
}

int init_suite_default(){
	return ZERO;
}


int clear_suite_default(){
	return ZERO;
}

int main(void) {
	CU_initialize_registry();
	CU_pSuite pSuite_A = CU_add_suite("SUITE A",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_A,"test of generate_array()",test_length);
	CU_pSuite pSuite_B = CU_add_suite("SUITE B",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_B,"test of mean()",test_mean);
	CU_pSuite pSuite_C = CU_add_suite("SUITE C",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_C,"test of ordered_array()",test_ordered_array);
	CU_pSuite pSuite_D = CU_add_suite("SUITE D",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_D,"test of bubble_sort()",test_bubble_sort);
	CU_pSuite pSuite_E = CU_add_suite("SUITE E",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_E,"test of median()",test_median);
	CU_pSuite pSuite_F = CU_add_suite("SUITE F",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_F,"test of linear_search()",test_linear_search);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
