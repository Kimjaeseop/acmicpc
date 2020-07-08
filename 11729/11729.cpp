#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int hanoi(int num, int from, int by, int to) 
{
	if (num==1)
		printf("%d %d\n", from, to);
	else {
		hanoi(num-1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(num-1, by, from, to);
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);
	printf("%d\n", (int)pow(2, N)-1);
	hanoi(N, 1, 2, 3);

	return 0;
}

