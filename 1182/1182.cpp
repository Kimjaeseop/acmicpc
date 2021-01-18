#include <stdio.h>
#include <algorithm>
#include <vector>

// 부분수열

int arr[32];

using namespace std;

int main(void)
{
	int N, S, count = 0;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i <= N; i++) { // i < N은 전부 다 1인 벡터를 생성하지 못하기 때문에 i <= N 사용
		if (S == 0 && i == 0)
			continue;

		vector<int> V(N-i, 0);

		for (int j = 0; j < i; j++) {
			V.push_back(1);
		}

		do {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (V[j] == 1) {
					//printf("%d ", arr[j]);
					sum += arr[j];
				}
			}
			//printf("\n");

			if (sum == S)
				count++;

			//printf("sum : %d, count : %d\n", sum, count);

		} while (next_permutation(V.begin(), V.end()));
	}

	printf("%d\n", count);

	return 0;
}

