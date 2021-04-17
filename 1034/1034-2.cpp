#include <iostream>
#include <string>

using namespace std;

string input;
int N, M, K;
long long bits[50];
int ANS;

void BFS(bool check[50][50], int depth) {
	if (depth == K) {
		int countVal = 0;

		for (int i = 0; i < N; i++) {
			bool rightON = true;

			for (int j = 0; j < M; j++) {
				if (!(bits[j] & (1 << i))) {
					rightON = false;
					break;
				}
			}

			if (rightON)
				countVal++;
		}

		if (countVal > ANS)
			ANS = countVal;

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				bits[i] = ~bits[i];
				check[i][j] = 1;

				BFS(check, depth+1);

				bits[i] = ~bits[i];
				check[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	bool check[50][50] = {{0,},};

	freopen("input_1.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;

		for (int j = 0; j < M; j++) {
			if (input[j] == '1')
				bits[j] |= (1 << i);
		}
	}

	cin >> K;
	BFS(check, 0);

	cout << ANS << endl;

	return 0;
}


