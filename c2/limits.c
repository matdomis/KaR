/* 
Exercise 2-1. 
Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

void rangeChar();
void rangeShort();
void rangeInt();
void rangeLong();

int main() {
    rangeChar();
    rangeShort();
    rangeInt();
    rangeLong();
    return 0;
}

void rangeChar() {
    printf("unsigned char %d\nsigned char %d\n", UCHAR_MAX, SCHAR_MAX);
}

void rangeShort() {
    printf("signed short %d\nunsigned short %u\n", SHRT_MAX, USHRT_MAX);
}

void rangeInt() {
    printf("signed int %d\nunsigned int %u\n", INT_MAX, UINT_MAX);
}

void rangeLong() {
    printf("signed long %ld\nunsigned long %lu\n", LONG_MAX, ULONG_MAX);
}