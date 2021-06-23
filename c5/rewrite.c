/*
Exercise 5-6. 
Rewrite appropriate programs from earlier chapters and exercises 
with pointers instead of array indexing. 
Good possibilities include getline (Chapters 1 and 4), 
atoi, itoa, and their variants (Chapters 2, 3, and 4), 
reverse (Chapter 3), and strindex and getop (Chapter 4).
*/

// All these functions are now recreated with pointers instead of brackets syntax
int get_line(char *);
void reverse(char *);
int atoi(char *);
void itoa(int, char *);
void itob(int, char *, int);
int strindex(char *, char *);
int getop(char *);

int get_line(char *line) {
	char c;
	while((c = getchar()) != EOF && c != '\n') {
		*line++ = c;
	}
	*line = '\0';
}

int atoi(char *s) {
	int sign = 1;
	int n = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	
	while(*s >= '0' && *s <= '9') 
		n = 10 * n + (*s - '0');
	
	return n*sign;
}

void itoa(int n, char *s) {
	int sign = 1;

	if (n < 0)
	{
		sign = -1;
		n *= sign;
	}

	int i = 0;
	do
	{
		*(s+i) = n%10 + '0';
		i++;
	} while((n /= 10) > 0);
	
	if (sign == -1)
	{
		*(s+i) = '-';
		i++;
	}
	
	*(s+i) = '\0';
	reverse(s);
}

void itob(int n, char *s, int b) {
	int rest, sign;
	int i;
	char hexnumbers[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	if((sign = n) < 0)
		n *= -1;

	i = 0;
	do
	{
		rest = n%b;
		if (rest >= 10)
			*(s+(i++)) = *(hexnumbers+rest-10);
		else
			*(s+(i++)) = rest + '0';
	}	while((n /= b) > 0);

	if (sign < 0)
		*(s+(i++)) = '-';
	*(s+i) = '\0';
	reverse(s);
}

void reverse(char *s) {
	int i, j;
	char c;

	for(i = 0 ; *(s+i) != '\0' ; i++);
	i--;
	for(j = 0 ; j < i ; j++, i--) 
		c = *(s+j), *(s+j) = *(s+i), *(s+i) = c; 
}

int strindex(char *orig, char *insideorig) {
	int j, i, k;
	int index = -1;
		
	for(i = 0 ; *(insideorig+i) != '\0' ; i++);

	for(j = 0 ; *(orig + j) != '\0' ; j++) {
		for(k = 0 ; k < i ; k++) {
			if (*(orig+j+k) != *(insideorig+k))
				break;
		}
		if (k == i)
			index = j;
	}
	return index;
}

int getop(char *s) {
	int i, c;
  	static char buf = EOF;

	if (buf == EOF || buf == ' ' || buf == '\t') {
    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s+1) = '\0';
  } 
  else
    c = buf;
    
  if (!isdigit(c) && c != '.')
    return c;   /* not a number */
    
  i = 0;
    
  if (isdigit(c)) /* collect integer part */
    while (isdigit(*(s+(++i)) = c = getch()));
    
  if (c == '.')   /* collect fraction part */
    while (isdigit(*(s+(++i)) = c = getch()));
    
  *(s+i) = '\0';
    
  if (c != EOF)
    buf = c;
  return NUMBER;
 }