#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1001];
int in[1001];

int main (void)
{
	int N;
	
	scanf("%d", &N);

	for (int i=1; i<=N; i++)
		scanf("%d", &in[i]);

	dp[0] = 0;
	
	for (int i=1; i<=N; i++)
		dp[i]=in[i];

	for (int i=2; i<=N; i++) {
		for (int j=1; j<=i; j++) {
			dp[i] = max(dp[j]+dp[i-j], dp[i]); // 이전까지의 조합과 i 한장 중 큰 값을 고름
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}
