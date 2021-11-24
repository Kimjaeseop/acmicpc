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
