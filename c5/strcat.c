/* 
Exercise 5-3. 
Write a pointer version of the function strcat that we 
showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
*/

void strcat(char *, char *);

void strcat(char *s, char *t) {
	int i;
	for(i = 0 ; *(s+i) != '\0' ; i++);
	for(; (*(s+i) = *t++) != '\0' ; i++);
}
