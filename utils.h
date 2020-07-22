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



#endif