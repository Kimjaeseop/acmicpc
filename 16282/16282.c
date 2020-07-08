#include <stdio.h>

long long N;
int A;

int main(void)
{
	scanf("%lld", &N);

	A = N;

	if (N == 1 || N == 2) {
		printf("1\n");
		return 0;
	}

	while (!(A == 2 || A == 1)) {
		N = ((N / 2) > (N - (N / 2)) ? (N / 2) : (N - (N / 2)));
		A = A - N;
	}

	printf("%d\n", (A == 1) ? 1 : 2);

	return 0;
}
