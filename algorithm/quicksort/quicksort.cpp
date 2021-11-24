#include <stdio.h>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int start, int end, int *arr)
{
	if (start >= end) return ;
	int low, high, pivot;
	int temp;

	low = start + 1;
	high = end;
	pivot = start;

	while (low <= high) {
		while (low <= end && arr[low] <= arr[pivot]) { low++; }
		while (high > start && arr[high] >= arr[pivot]) { high--; }

		temp = arr[high];
		if (low > high) {
			arr[high] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			arr[high] = arr[low];
			arr[low] = temp;
		}
	}

	quickSort(start, high-1, arr);
	quickSort(high+1, end, arr);
}

int main(void)
{
	int N;
	int arr[100001] = {0, };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	quickSort(0, N-1, arr);

	return 0;
}
