#include <stdio.h>

int L;
char str[51];
unsigned long long sum;
unsigned long long r = 1;
long long M = 1234567891;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &L);
	scanf("%s", str);

	for (int i = 0; i < L; i++) {
		sum += (str[i] - 'a' + 1) * r;

		r *= 31;
		r %= M; // r또한 31^50이면 약 2^5^50 == 2^250이므로 unsigned long long의 범주를 벗어남
		sum %= M;
	}

	printf("%lld\n", sum % M);
	
	return 0;
}
