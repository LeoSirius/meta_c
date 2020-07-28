#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

void test_is_equal_str()
{
    bool is_passed = true;
    char str1[] = "123";
    char str2[] = "123";
    char str3[] = "12";

    if (!is_equal_str(str1, str2)) {
        printf("!is_equal_str(str1, str2)\n");
        is_passed = false;
    }

    if (is_equal_str(str1, str3)) {
        printf("is_equal_str(str1, str3)\n");
        is_passed = false;
    }

    if (is_passed)
        printf("test1 success.\n");
    else
        printf("test1 failed\n");

}

int main()
{
    test_is_equal_str();
    return 0;
}