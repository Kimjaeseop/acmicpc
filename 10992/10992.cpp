#include <iostream>

using namespace std;

int main (void)
{
	int N;

	cin >> N;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N+i; j++) {
			if ((j==N-1-i) || (j==N-1+i) || (i==N-1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
