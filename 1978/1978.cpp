#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[2000];
int N;
int MAX;
int SUM;

int main (void)
{
	scanf("%d", &N);
	vector <int> V (N);

	for (int i=0; i<N; i++)
		scanf("%d", &V[i]);

	MAX = *max_element(V.begin(), V.end());

	arr[1] = 1;

	for (int i=2; i<=MAX/2; i++) {
		for (int j=2; j<=MAX; j++) {
			if (i*j>MAX)
				break;
			else
				arr[i*j]=1;
		}
	}

	MAX = V.size();

	for (int i=0; i<MAX; i++)
		if (!arr[V[i]])
			SUM++;

	printf("%d\n", SUM);

	return 0;
}
