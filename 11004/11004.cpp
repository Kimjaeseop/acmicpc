#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);
	vector <int> V(N);

	for (int i=0; i<N; i++)
		scanf("%d", &V[i]);

	sort (V.begin(), V.end());

	printf("%d\n", V[K-1]);

	return 0;
}
