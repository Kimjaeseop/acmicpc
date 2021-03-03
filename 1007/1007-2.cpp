#include <cmath>
#include <vector>
#include <algorithm>

#include <stdio.h>

#define min(a, b) a > b ? b : a

// v1 = 선분AB, v2 = 선분CD
// v1, v2의 합은 B좌표 - A좌표 + D좌표 - C좌표
// 즉, 도착점 - 시작점
// 좌표를 두 그룹으로 나누고 도착점을 모두 더 하고 시작점을 모두 빼면 벡터의 합을 찾을 수 있다.

using namespace std;

int N, T;
double MIN = 10e7;
int arr[21][2];
long long X, Y;

double pitagoras(int x1, int x2, int y1, int y2) {
	return pow(x1-x2, 2) + pow(y1-y2, 2);
}

int main(void) {

	//freopen("input_1.txt", "r", stdin);

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		MIN = 0x7fffffffffffffffLL;

		for (int i = 0; i < N; i++) 
			scanf("%d %d", &arr[i][0], &arr[i][1]);

		if (N == 2)
			printf("%.6f\n", sqrt(pitagoras(arr[0][0], arr[1][0], arr[0][1], arr[1][1])));
		else {
			vector<int> flags;
			flags.resize(N/2, 0);

			for (int i = 0; i < N/2; i++)
				flags.push_back(1);

			do {
				X = Y = 0;

				for (int i = 0; i < N; i++) {
					if (!flags[i]) {
						X += arr[i][0];
						Y += arr[i][1];
					}
					else {
						X -= arr[i][0];
						Y -= arr[i][1];
					}
				}

				MIN = min(MIN, (X*X) + (Y*Y));
			} while (next_permutation(flags.begin(), flags.end()));

			printf("%.6f\n", sqrt(MIN));
		}
	}

	return 0;
}



