#include <stdio.h>

int fact (int n)
{
	if (!n)
		return 1;

	for (int i = n-1; i != 0; i--) 
		n *= i;

	return n;
}

int combination (int n, int r)
{
	if (!(n-r))
		return 1;
	else
		return fact(n)/(fact(r)*fact(n-r));
}
// 런타임에러로 불가능
int main (void)
{
	int N;
	int P=0; // 세로로 서있는 타일 개수
	int tmp;
	int sum=0;

	scanf("%d", &N);

	if (N%2==1) { // 세로 타일 짝수 불가능
		for (P=1; P<=N; P+=2) {
			tmp = (N-P)/2;
			sum += (combination(tmp+P, P))%10007;
		}
	}
	else { // 세로 타일 홀수 불가능
		for (P=0; P<=N; P+=2) {
			tmp = (N-P)/2;
			sum += (combination(tmp+P, P))%10007;
		}
	}

	printf("%d\n", sum);

	return 0;
}
