#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> V;
int arr[1000001];
int IN;
int MAX;
int DIFF;
int A, B;
int SIZE;
int F;

int main (void)
{
	for (int i=0; ; i++) {
		scanf("%d", &IN);

		if (!IN) break;
		else V.push_back(IN);
	}

	MAX = *max_element(V.begin(), V.end());

	arr[1] = 1;

	for (int i=2; i<=MAX/2; i++) {
		for (int j=2; j<=MAX; j++) {
			if (i*j > MAX)
				break;

			arr[i*j]=1;
		}
	}

	SIZE = V.size();

	for (int i=0; i<SIZE; i++) {
		for (int p=V[i]; p>0; p--) {
			for (int q=0; q<MAX; q++) {
				if (!arr[p] && !arr[q] && p+q==V[i]) {
					A = p;
					B = q;
					F = 1; 
					break;
				}
				if (p+q > V[i]) // 중간에 끊어주지 않으면 시간초과뜬다.
					break; 
			}
			if (A && B) {
				printf("%d = %d + %d\n", V[i], B, A);
				A = B = 0;
				F = 0;
				break;
			}
			else if (F)
				printf("Goldbach's conjecture is wrong.\n");
			F = 0;
		}
	}

	return 0;
}
