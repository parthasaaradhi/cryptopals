#include<stdio.h>
#include<stdlib.h>

unsigned char* xor_bit_stream(unsigned char* a, unsigned char* b, int size) {
	unsigned char* c; int i;
	c = (char*) malloc(size*sizeof(char));
	for(i=0;i<size;i++)
		c[i] = a[i]^b[i];
	return c;
}
