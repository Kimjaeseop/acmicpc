#include <stdio.h>
#include <unistd.h>

int T;
int M, N, X, Y;

// 다 해결하고 T_1 % N이 0이 되는 경우를 어떻게 처리해야 할지 도저히 몰랐는데
// 검색해서 찾았다. 단순히 0이되면 N을 재할당 해주면 되는 것인데,,,,,,

// 런타임 속도가 생각보다 느려서 다른 사람의 코드를 보니 경이롭다
// https://www.acmicpc.net/source/9979871

int gcd(int a, int b) // 최대공약수
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d %d", &M, &N, &X, &Y);

		long long cycle = 0;
		int l = lcm(M, N);

		while (1) {
			int T_1 = cycle + X;
			int T_2 = T_1 % N == 0 ? N : T_1 % N;

			if (T_2 == Y) {
				printf("%d\n", T_1);
				break;
			}

			if (l <= cycle) {
				printf("-1\n");
				break;
			}

			cycle += M;
		}
	}

	return 0;
}
