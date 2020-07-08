#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int dp[100001];
int N;
int tmp;
int step;

int recur (int N) {
	if (N != 0) {
		step++;
		return recur(N-pow((int)sqrt(N), 2));
	}
}
int main(void)
{
	cin >> N;
	recur (N);
	cout << step << endl;

	return 0;
}
