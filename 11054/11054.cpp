#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int in[1001];
	int dp[1001][2];
	int N;
	int ans=0;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i=0; i<1001; i++) // 기본 길이 1지정
		fill(dp[i], dp[i]+2, 1);

	for (int i=0; i<N; i++)
		scanf("%d", &in[i]);

	for (int i=0; i<N; i++) { // index 0부터 오름차순 길이
		for (int j=0; j<i; j++)
			if (in[i]>in[j] && dp[j][0]+1 > dp[i][0])
				dp[i][0] = dp[j][0]+1;
	}

	for (int i=N-1; i>=0; i--) { // index N부터 역순으로 오름차순 길이
		for (int j=N-1; j>i; j--) {
			if (in[i]>in[j] && dp[j][1]+1 > dp[i][1])
				dp[i][1] = dp[j][1]+1;
		}
	}

	for (int i=0; i<N; i++) { // 같은 인덱스의 합 - 1 중 가장 큰 값
		if (dp[i][0]+dp[i][1]-1 > ans)
			ans = dp[i][0]+dp[i][1]-1;
	}

	cout << ans << endl;

	return 0;
}

