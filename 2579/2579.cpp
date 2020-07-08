#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int in[301] = {0,};
int dp[301] = {0,};

// 임의의 목적지에 오를 수 있는 경우는

// 1. 한 개의 계단을 오른 경우
// 2. 두 개의 계단을 오른 경우
// 두 가지 뿐이다
// 1 2 2 1
// 1 2 1 2
// 2 1 1 2
// 2 1 2 1

int main(void) {
	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i=1; i<=N; i++)
		cin >> in[i];

	dp[0] = in[0];

	for (int i=1; i<=N; i++)
		dp[i] = max(dp[i-3]+in[i-1], dp[i-2]) + in[i];
	// max(한 칸의 계단을 오를 경우, 두 칸의 계단을 오를 경우) + 현재 계단의 수

	cout << dp[N] << endl;

	return 0;
}


