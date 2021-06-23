/*
Exercise 5-4. 
Write the function strend(s,t), 
which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
*/

int strend(char *, char *);

int strend(char *s, char *t) {
	int i, j;

	for(i = 0 ; *(s+i) != '\0' ; i++);
	for(j = 0 ; *(t+j) != '\0' ; j++);

	int diff = i-j;
	if (diff < 0)
		return 0;

	for(i = 0 ; *(t+i) != '\0' ; i++)
		if (*(s+diff++) != *(t+i))
			return 0;
	return 1;
}