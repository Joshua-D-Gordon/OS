#include <stdio.h>

int main()
{
    int *ptr = NULL;
    *ptr = 42;  // Dereferencing a null pointer, leading to a segmentation fault

    return 0;
}