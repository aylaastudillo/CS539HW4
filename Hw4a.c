// CS 539, Hw4, Ayla Astudillo Hello World

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void show(unsigned a[], unsigned elms);
void new1(const unsigned a[], unsigned elms, unsigned new[], int b, int *c, int *d);
void sort0(unsigned new[], unsigned elms, int b, int *c, int *d);
void qsort(void * ptr, unsigned elms, unsigned bpe, int compare(const void * p0, const void * p1));
int comp1(const void * ptr0, const void * ptr1);

int main()
{
	unsigned ar[] = { 5,0,5,7,4,2,6,0,9,1,2 }, new[11] = { 0 };
	unsigned elements = 11;
	int b = 0, *c = 0, *d = 0;
	printf("Original[] = {");
	show(ar, elements);
	new1(ar, elements, new, b, &c, &d);
	sort0(new, elements, b, c, d);
	qsort(ar, elements, sizeof(*new), comp1);
	printf("sort1[] {");
	show(ar, elements);



}
void show(unsigned a[], unsigned elms)
{
	unsigned i = 0;
	for (; i < elms; i++)
		printf("%u  ", a[i]);
	printf("}\n");
}
void new1(const unsigned a[], unsigned elms, unsigned new[], int b, int *c, int *d)
{
	unsigned i = 0;

	for (; i < elms; i++)
	{
		if (a[i] % 2 == 0 && a[i] != 0)
			new[b++] = a[i];
	}
	*c = b;
	
	for (i = 0; i < elms; i++)
	{
		if (a[i] % 2 != 0)
			new[b++] = a[i];
	}
	*d = b;
	for (i = 0; i < elms; i++)
	{
		if (a[i] == 0)
			new[b++] = a[i];
	}
	//printf("\nb= %i", b);
	//printf("\nc= %x", *c);
	//printf("\nd= %x\n", *d);

	//printf("New[] {");
	//show(new, elms);
}

void sort0(unsigned new[], unsigned elms, int b, int *c, int *d)
{
	//printf("\nb= %i", b);
	//printf("\nc= %i", c);
	//printf("\nd= %i\n", d);

	for (unsigned j = 0; j < 4; j++)
	{
		int t = new[j];
		unsigned i = j;
		for (; i > 0 && new[i - 1] > t; i--)
			new[i] = new[i - 1];
		new[i] = t;
	}
	for (unsigned j = c; j < d; j++)
	{
		int t = new[j];
		unsigned i = j;
		for (; i > c && new[i - 1] < t; i--)
			new[i] = new[i - 1];
		new[i] = t;
	}

	printf("Sort[]={ ");
	show(new, elms);
}
int comp1(const void * x, const void * y)
{
	// increasing order
	int xNum = *(const int *)x;
	int yNum = *(const int *)y;
	
	if (xNum == 0) {
		return xNum < yNum ? -1 : xNum > yNum ? 1 : 0;
	}
	if (xNum % 2 != 0) {//odd
		return xNum < yNum && yNum %2 == 1? -1 : xNum > yNum && yNum %2 == 1 ? 1 : -1;
	}else { //even
		return xNum > yNum && yNum %2 == 0 ? -1 : xNum < yNum && yNum % 2 == 0 ? 1 : 1;
	}
	
	
}

