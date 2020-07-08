#include <stdio.h>

int N;
long long F;
int CNT;

int main (void) // 개대충짰는데 맞았다...
{
	scanf("%d", &N);

	F = 1;

	for (long long i=N; i>0; i--) {
		F *= i;

		while (1) {
			if (F%10)
				break;

			CNT++;

			F/=10;
		}
		F %= 10000;
	}

	printf("%d\n", CNT);

	return 0;
}

// 정석 풀이는 (2*5)의 쌍을 찾는 것인거 같다.
// (4*5) 등도 다 되지만 어차피 5와 짝을 이루어야 하기 때문에
// 5의 개수만 세주면 된다.
// (N/5) + (N/25) + (N/125)


