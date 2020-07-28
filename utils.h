#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

/* assume two arrs' length is equal */
bool is_equal_array(int *arr1, int *arr2, int len)
{
    for (int i = 0; i < len; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

bool is_equal_str(const char *s1, const char *s2)
{
    const char *p1 = s1, *p2 = s2;
    while (*p1 && *p2) {
        if (*p1++ != *p2++) return false;
    }
    return *p1 == '\0' && *p2 == '\0';
}



#endif