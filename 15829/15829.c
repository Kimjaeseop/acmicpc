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
		r %= M; // r���� 31^50�̸� �� 2^5^50 == 2^250�̹Ƿ� unsigned long long�� ���ָ� ���
		sum %= M;
	}

	printf("%lld\n", sum % M);
	
	return 0;
}
