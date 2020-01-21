#include<stdio.h>
#include<stdlib.h>
#include "hex.h"
#include "base64.h"
#include "utility.h"

int main() {
	unsigned char *input, *full_bit, *base64_bit;
	int digits;
	fill_base64_code();

	digits = read_input_char(&input);
	full_bit = convert_hexa_full_bit_stream(input, digits);
	free(input);

	base64_bit = convert_full_bit_stream_base64(full_bit, digits/2 + (digits%2));
	free(full_bit);

	print_char(base64_bit, base64_number(digits/2 + (digits%2)));
	printf("\n");
	free(base64_bit);
	return 0;
}
