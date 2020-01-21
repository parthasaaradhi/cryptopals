#include<stdio.h>
#include<stdlib.h>

unsigned char base64_code[64];

void fill_base64_code() {
	unsigned int i,n;
	unsigned char c;
	n=65;
	for(i=0;i<64;i++)
	{
		c=n;
		base64_code[i] = c;
		n++;
		if(n == 91)
			n=97;
		if(n == 123)
			n=48;
		if(n == 58)
			n=43;
		if(n == 44)
			n=47;
	}
	return;
}

unsigned char six_bit_base64(unsigned char c) {
	unsigned int n;
	n = c;
	return base64_code[n];
}

int base64_number(int n) {
	return (8*n/6 + (n%3==0? 0 : 1));
}

unsigned char * convert_full_bit_stream_base64(unsigned char* input, int length) {

	int i;
	unsigned char* base64_stream;
	unsigned int temp;
	i = base64_number(length);
	base64_stream = (char*) malloc(i*sizeof(char));
	while(length>=3) {
		temp = input[length-3]<<16 | input[length-2]<<8 | input[length-1];
		base64_stream[i-1] = six_bit_base64((temp<<26)>>26);
		base64_stream[i-2] = six_bit_base64((temp<<20)>>26);
		base64_stream[i-3] = six_bit_base64((temp<<14)>>26);
		base64_stream[i-4] = six_bit_base64((temp<<8)>>26);
		length = length-3;
		i = i-4;
	}
	if(length == 2) {
		temp = input[length-2]<<8 | input[length-1];
		base64_stream[i-1] = six_bit_base64((temp<<26)>>26);
		base64_stream[i-2] = six_bit_base64((temp<<20)>>26);
		base64_stream[i-3] = six_bit_base64((temp<<14)>>26);
		length = length-2;
		i = i-3;
	}
	if(length == 1) {
		temp = input[length-1];
		base64_stream[i-1] = six_bit_base64((temp<<26)>>26);
		base64_stream[i-2] = six_bit_base64((temp<<20)>>26);
		length = length-1;
		i = i -2;
	}
	return base64_stream;
}
