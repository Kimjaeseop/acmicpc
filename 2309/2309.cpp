#include <stdio.h>
#include <iostream> // 비교함수인 less를 위해 필요
#include <vector>
#include <algorithm>

using namespace std;

int main (void)
{
	vector<int> V(9); // 메모리 확보

	freopen("input.txt", "r", stdin);

	for (int i=0; i<9; i++)
		scanf("%d", &V[i]);

	sort(V.begin(), V.end(), less<int>());
	//sort(V.begin(), V.end());

	do {
		int sum=0;

		for (int i=0; i<7; i++)
			sum += V[i];

		if (sum==100) {
			for (int i=0; i<7; i++)
				printf("%d\n", V[i]);
			break;
		}
	} while (next_permutation(V.begin(), V.end()));

	return 0;
}
