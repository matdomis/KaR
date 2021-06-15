/*
Exercise 3-1. 
Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.
*/

#include <stdio.h>

int binsearch(int *, int, int);

int main() {
	int v[] = {1,3,5,7,9,11,15,20,25,29,30};
	int tam = 11;
	int p, x;

	scanf("%d", &x);
	p = binsearch(v, x, tam);

	printf("%d\n", p);
	return 0;
}

int binsearch(int v[], int x, int tam) {
	int low = 0;
	int high = tam-1;
	int mid;

	while (low <= high && v[mid] != x) {	
		mid = (high+low)/2;
		if (v[mid] > x)
			high = mid+1;
		else
			low = mid;
	}

	if (v[mid] == x)
		return mid;
	return -1;
}