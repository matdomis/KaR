/*
Exercise 1-23. 
Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

// Note: This program just handles "/* */" comments.

#include <stdio.h>

#define MAX 10000

#define IN 1
#define OUT 0

void main(void) {
    char source[MAX];
   
    char c, lastc;
    char quote;

    int in_comment = OUT;   // Check if is i in comment
    int in_quotes = OUT;    // Check if is i in quote

    int i = 0;
    while((c = getchar()) != EOF) {
        if ((c == '\'' || c == '\"') && in_comment == OUT && in_quotes == OUT) {
            quote = c;
            in_quotes = IN;
        }

        else if (in_quotes == IN && c == quote)
            in_quotes = OUT;
        
        if (c == '*' && lastc == '/' && in_comment == OUT && in_quotes == OUT) {
            in_comment = IN;
            i--;
        }

        if (!in_comment)
            source[i++] = c;
        
        if(c == '/' && lastc == '*')
            in_comment = OUT;
            
        lastc = c;
    }
    
    source[i] = '\0';
    printf("\n\n%s", source);
}