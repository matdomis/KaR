/*
Exercise 3-4. 
In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2 wordsize-1 ). 
Modify it to print that value correctly, regardless of the machine on which it runs.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
    char buffer[20];
    
    printf("INT_MIN: %d\n", INT_MIN);
    itoa(INT_MIN, buffer);
    printf("Buffer : %s\n", buffer);
    
    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    sign = n;
    
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ( n /= 10 );
    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}