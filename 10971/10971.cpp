#include <iostream>

using namespace std;

int W[10][10];
int N, MIN;

void func(int start, int prev, int cost, int check)
{
	if (cost > MIN)
		return ;

	if (check == (1 << N) - 1) {
		if (W[prev][start] != 0 && MIN > (cost + W[prev][start]))
			MIN = cost + W[prev][start];

		return ;
	}

	for (int i = 0; i < N; i++) {
		if (W[prev][i] != 0 && !(check & 1 << i)) {
			func(start, i, cost + W[prev][i], (check | 1 << i));
		}
	}
	// 끝 점과 시작점이 연결되어 있는지 확인해야 함
}

int main(void)
{    
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	freopen("input_2.txt", "r", stdin);

	cin >> N;

	MIN = 1e9;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	for (int i = 0; i < N; i++) {
		func(i, i, 0, 1 << i);
	}

	cout << MIN << endl;

	return 0;
}

