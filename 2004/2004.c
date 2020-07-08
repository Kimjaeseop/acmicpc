#include <stdio.h>

// 0의 개수는 2 or 5의 개수로 정해지는데
// (2 * 5)의 짝의 개수로 정해진다.
// 짝이 이뤄져야하기 때문에 소인수분해를 해서 적은 수를 택해서 계산
// N! 의 2or5의 개수 - (R!의 개수 + (N-R)!의 개수)

// EX ) 5! / 2! = 5*4*3*2*1 / 2*1 = 5*4*3*1 = 60
// 5 : 1개, 2 : 2개 
// 답 : 1개

// combination 공식
// N! / (R! * (N-R)!)
// 팩토리얼 0의 개수 세는 법은 1676번 참고

int zero (int N, int div)
{
	int CNT=0;

	for (long long i = div; i <= N; i *= div)
		CNT += N/i;

	return CNT;
}

int main (void)
{
	int N, M;
	long long T, F;

	scanf ("%d %d", &N, &M);

	T = zero (N, 2) - zero(M, 2) - zero(N-M, 2);
	F = zero (N, 5) - zero(M, 5) - zero(N-M, 5);

	printf ("%lld\n", T > F ? F : T);

	return 0;
}

