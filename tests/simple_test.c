#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <stdbool.h>



int my_max(int a, int b) {
    return (a>b) ? a:b;
};

int __real_my_max(int,int);

int __wrap_my_max(int a, int b) {

//bool print_bool = mock_type(bool);
//if (print_bool) 
//   printf("%d %d\n",a,b);
return mock();
}

int get_max(int a, int b) {
  return my_max(a,b);
}


/* A test case that does nothing and succeeds. */
static void test_max(void **state) {

//will_return(__wrap_my_max, true);
will_return(my_max, 10);

assert_int_equal(get_max(4,10), 10);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_max),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}