#include <stdio.h>

int T;
int N;
long long dp[101];
int j;

int main(void) {
	scanf("%d", &T);

	dp[0]=1; dp[1]=1; dp[2]=1;
	dp[3]=2; dp[4]=2;
	j=5; // j==5���� ������������ �����ϸ�, ���� ����� ��Ÿ����
	// dp[N] = dp[N-1]+dp[N-5]

	for (int i=0; i<T; i++) {
		scanf("%d", &N);

		if (dp[N]==0) {
			for (; j<N; j++) {
				dp[j] = dp[j-1]+dp[j-5];
			}
		}

		printf("%lld\n", dp[N-1]);
	}

	return 0;
}
