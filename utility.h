#include<stdio.h>
#include<stdlib.h>

int read_input_char(unsigned char **pl) {
	unsigned char c;
	int i=0;
	*pl = malloc(0);
	while(scanf("%c", &c)) {
		if(c == EOF || c == ' ' || c == '\n')
			break;
		*pl = realloc(*pl, ((i+1)*sizeof(char)));
		(*pl)[i] = c;
		i++;
	}
	return i;
}

void print_char(unsigned char *l, int d) {
	int i;
	for(i=0;i<d;i++)
		printf("%c", l[i]);
	printf("\n");
	return;
}

void print_num(unsigned char* l, int d) {
	int i = 0;int n;
	for(i=0;i<d;i++) {
		n = l[i];
		printf("%d", n);
	}
	printf("\n");
	return;
}
