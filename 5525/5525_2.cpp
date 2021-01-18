#include <iostream>
#include <bitset>

using namespace std;

#define MAX 1000001
//#define MAX 20

bitset <MAX> bit;
bitset <MAX> P;
int N, M, CNT;
char c;

int main(void) {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> c;

		if (c == 'O')
			bit[i] = 0;
		else if (c == 'I')
			bit[i] = 1;
	}

	P[0] = 1;

	for (int i = 1; i <= N; i++)
		P[2*i] = 1;

	for (int i = 0; i < M; i++) {
		if (((bit >> i) & P) == P) {
			i += (N-1);
			CNT++;
		}
	}

	cout << CNT << endl;

	return 0;
}
