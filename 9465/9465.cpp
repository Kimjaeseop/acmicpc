#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

// 얼핏봐서 bfs 문제 같다.

// max(dp[i-1] + N, dp[i-2] + N)
// 이후 커서 지정

int main(void)
{
	int in[2][100001]={0,};
	int dp[2][100001]={0,};
	int T;
	int N;
	int tmp=0;

	scanf("%d", &T);

	for (int t=0; t<T; t++) {
		scanf("%d", &N);

		for (int i=0; i<=1; i++) // input
			for (int j=1; j<=N; j++)
				scanf("%d", &in[i][j]);

		dp[0][1]=in[0][1]; // 맨 처음 값 설정
		dp[1][1]=in[1][1];

		// 현재 값과 반대 패턴의 합이 더 큰 경우를 고려
		for (int i=2; i<=N; i++) { // MAX(이전값, 두 단계 전의 반대 위치 값) + 현재 값
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + in[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + in[1][i];
		}

		printf("%d\n", max(dp[0][N],dp[1][N]));
	}

	return 0;
}

