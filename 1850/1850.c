#include <stdio.h>

// 유클리드 호제법 사용

long long gcd (long long A, long long B)
{
	return (A%B==0 ? B : gcd(B, A%B));
}

int main (void)
{
	long long input1, input2;

	freopen("input.txt", "r", stdin);

	scanf("%lld %lld", &input1, &input2);

	for (int i=0; i < gcd(input1, input2); i++)
		printf("1");

	return 0;
}


