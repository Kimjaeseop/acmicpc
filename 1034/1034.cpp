#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<bool>> V;
vector<vector<bool>> check;
int N, M, K;
int ANS;
int input;

void columnFlip(vector<vector<bool>> &V, int idx) {
	for (int i = 0; i < N; i++) {
		V[i][idx] = !V[i][idx];
	}
}

void findAnswer(vector<vector<bool>> V, vector<vector<bool>> check, int depth) {
	if (depth == K) {
		int countVal = 0;

		for (int i = 0; i < N; i++) {
			bool rightON = true;

			for (int j = 0; j < M; j++) {
				if (V[i][j] == 0) {
					rightON = false;
					break;
				}
			}
			if (rightON)
				countVal++;
		}

		if (countVal > ANS)
			ANS = countVal;

		return ;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				columnFlip(V, i);
				check[i][j] = 1;

				findAnswer(V, check, depth+1);

				columnFlip(V, i);
				check[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	V.resize(N);
	check.resize(N);
	
	for (int i = 0; i < N; i++) {
		V[i].resize(M);
		check[i].resize(M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &input);

			if (input == 0)
				V[i][j] = 0;
			else
				V[i][j] = 1;
		}
	}

	scanf("%d", &K);

	findAnswer(V, check, 0);

	printf("%d\n", ANS);

	return 0;
}

