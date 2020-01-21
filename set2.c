#include<stdio.h>
#include<stdlib.h>
#include "hex.h"
#include "utility.h"
#include "xor_stream.h"

int main()
{
	unsigned char *a, *b, *full_a, *full_b, *result, *answer;
	int digits;
	digits = read_input_char(&a);
	digits = read_input_char(&b);
	full_a = convert_hexa_full_bit_stream(a, digits);
	full_b = convert_hexa_full_bit_stream(b, digits);
	result = xor_bit_stream(full_a, full_b, digits/2 + (digits%2));
	free(a);free(b); free(full_a); free(full_b);
	answer = convert_full_bit_stream_hexa(result, digits/2 + (digits%2));
	free(result);
	print_char(answer, digits + digits%2);
	free(answer);
	return 0;
}
