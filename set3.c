#include<stdio.h>
#include<stdlib.h>
#include "utility.h"
#include "hex.h"
char freq[12] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D','L','U'};
int main() {
	unsigned char *input, *answer, *result;
	int i,j,max;
	max = 0;
	digits = read_input_char(&input);
	result = convert_hexa_full_bit_stream(input, digits);
	for(j=0;j<12;j++) {
		for(i=0;i<digits;i++) {
			input[i]^freq[j];
