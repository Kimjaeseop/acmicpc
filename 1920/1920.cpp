#include <stdio.h>
#include <algorithm>

using namespace std;

int binarySearch(int start, int end, int key, int *arr)
{
	if (key > arr[end] || key < arr[start] || start > end) return 0;

	int mid = (start + end) / 2;

	if (arr[mid] == key) {
		return 1;
	}
	else if (arr[mid] < key) {
		return binarySearch(mid+1, end, key, arr);
	}
	else {
		return binarySearch(start, mid-1, key, arr);
	}
}

int main(void)
{
	int arrN[100001] = {0, };
	int arrM[100001] = {0, };
	int N, M, num;

	freopen("input_1.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arrN[i]);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &arrM[i]);
	}

	sort(arrN, arrN+N);

	for (int i = 0; i < M; i++) {
		printf("%d\n", binarySearch(0, N-1, arrM[i], arrN));
	}

	return 0;
}
