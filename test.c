#include<stdio.h>
#include<stdlib.h>
#include "hex.h"
#include "utility.h"
int main()
{
	unsigned char c;
	unsigned int d;
	d = 0;
	c = d;
	c = c + 45;
	printf("%c\n",c);
	return 0;
}
