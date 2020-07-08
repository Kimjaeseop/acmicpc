#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int dp[100001];
int ans[100001];
int N;
int tmp;
int step;

int main(void)
{
	int s=0;
	cin >> N;

	s = sqrt(N);

	for (int i=0; i<=s; i++) {
		int tmp = i*i; 
		dp[tmp]=1;
	}

	if (dp[N]==1) {
		cout << dp[N] << endl;
		return 0;
	}

	for (int i=1; i<=N; i++) {
		if (dp[i]==1)
			continue;
		for (int j=1; j<i/2; j++) {
			if (j==1)
				dp[i]=dp[j]+dp[i-j];
			else
				dp[i]=min(dp[i], dp[j]+dp[i-j]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}
