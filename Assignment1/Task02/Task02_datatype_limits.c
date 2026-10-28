/*
Task 2 - Check sizes and ranges on your own system
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("char: %zu byte, range %d to %d\n",
           sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short: %zu bytes, range %d to %d\n",
           sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %zu bytes, max %u\n",
           sizeof(unsigned short), USHRT_MAX);
    printf("int: %zu bytes, range %d to %d\n",
           sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int: %zu bytes, max %u\n",
           sizeof(unsigned int), UINT_MAX);
    printf("long: %zu bytes, range %ld to %ld\n",
           sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long: %zu bytes, range %lld to %lld\n",
           sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("float: %zu bytes, FLT_MAX=%g, FLT_EPSILON=%g\n",
           sizeof(float), FLT_MAX, FLT_EPSILON);
    printf("double: %zu bytes, DBL_MAX=%g, DBL_EPSILON=%g\n",
           sizeof(double), DBL_MAX, DBL_EPSILON);
    return 0;
}
