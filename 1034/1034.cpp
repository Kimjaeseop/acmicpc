#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> V;
vector<vector<bool>> check;
int N, M, K;
int ANS;
char c;

void column
void findAnswer(vector<vector<bool>> V, vector<vector<bool>> check, int depth) {
	if (depth == K) {
		int countVal = 0;
		for (int i = 0; i < N; i++) {
			bool rightON = true;

			for (int j = 0; j < N; j++) {
				if (V[j] == 0) {
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
			cin.get(c);

			if (c == '0')
				V[i][j] = 0;
			else
				V[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << V[i][j];
		}
		printf("\n");
	}

	scanf("%d", &K);

	findAnswer(V, check, 0);

	printf("%d\n", ANS);

	return 0;
}

