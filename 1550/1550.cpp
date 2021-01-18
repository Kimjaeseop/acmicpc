#include <stdio.h>
#include <string.h>

int tmp;
long long N, base;
char in[7];

int main(void)
{
	base = 1;
	scanf("%s", in);

	int len = strlen(in);

	for (int i = len-1; i >= 0; i--) {
		if ('0' <= in[i] && '9' >= in[i])
			tmp = in[i] - '0';
		else if ('A' <= in[i] && 'F' >= in[i])
			tmp = in[i] - 'A' + 10;

		N += tmp * base;
		base *= 16;
	}
	
	printf("%lld\n", N);

	return 0;
}

