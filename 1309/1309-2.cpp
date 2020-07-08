#include <stdio.h>

int arr[100001][3];

int main (void)
{
	int N;

	scanf("%d", &N);

	// [0] X X
	// [1] X O
	// [2] O X

	arr[1][0] = arr[1][1] = arr[1][2] = 1;




