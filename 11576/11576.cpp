#include <iostream>
#include <stack>

using namespace std;

int A, B, M;
int IN;
int N;
int TMP;
int DEC;

stack <int> S;

int main (void)
{
	scanf("%d %d %d", &A, &B, &M);

	for (int i=0; i<M; i++) {
		scanf("%d", &IN);
		S.push(IN);
	}

	N = 1;

	while (S.size()) {
		DEC += S.top()*N;

		N *= A;
		S.pop();
	}

	N = 1;

	while (1) {
		TMP = DEC % B;

		if (!DEC)
			break;

		S.push(TMP);
	
		DEC /= B;
	}

	while (S.size()) {
		printf("%d ", S.top());
		S.pop();
	}

	printf("\n");

	return 0;
}
