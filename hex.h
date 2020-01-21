#include<stdlib.h>

unsigned char half_bit_one_hexa(unsigned char c) {
	if(c>-1 && c<10)
		return c+48;
	if(c>9 && c<16)
		return c+87;
}

unsigned char one_hexa_half_bit(unsigned char c) {
	if(c>64 && c<91)
		return c-55;
	if(c>96 && c<123)
		return c-87;
	if(c>47 && c<58)
		return c-48;
	return '\n';
}

unsigned char two_hexa_full_bit(unsigned char c1, unsigned char c2) {
	return (one_hexa_half_bit(c1) | (one_hexa_half_bit(c2) << 4));
}

unsigned char* convert_hexa_full_bit_stream(unsigned char* input, int length) {
	unsigned char* full_bit;
	int i;
	if(length%2 ==0)
		i = length/2;
	else
		i = length/2 + 1;
	full_bit = (char*) malloc(i*sizeof(char));
	while(length >1) {
		full_bit[i-1] = two_hexa_full_bit(input[length-1], input[length-2]);
		length=length-2;
		i--;
	}
	if(length == 1)
		full_bit[0] = one_hexa_half_bit(input[0]);
	return full_bit;
}

unsigned char* convert_full_bit_stream_hexa(unsigned char* input, int length) {
	unsigned char* hexa_stream;
	int i;
	unsigned char temp;
	i = 2*length;
	hexa_stream = (char*) malloc(i*sizeof(char));
	while(length>=1) {
		temp = input[length-1]<<4;
		temp = temp>>4;
		hexa_stream[i-1] = half_bit_one_hexa(temp);
		temp = input[length-1]>>4;
		hexa_stream[i-2] = half_bit_one_hexa(temp);
		i=i-2;
		length--;
	}
	return hexa_stream;
}
