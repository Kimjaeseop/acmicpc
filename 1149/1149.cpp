#include <iostream>
#include <queue>
#include <utility>

using namespace std;

short arr[1000][3];
int N;
int depth;
int MIN = 1000000;

void DFS(short prev, int count, int depth) {
	if (MIN < count)
		return ;

	if (depth == N) {
		if (MIN > count)
			MIN = count;

		return ;
	}

	for (short i = 0; i < 3; i++) {
		if (prev != i)
			DFS(i, count + arr[depth][i], depth+1);
	}
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	cin >> N;

	for (short i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (short i = 0; i < 3; i++) 
		DFS(i, arr[0][i], 1);

	cout << MIN << endl;

	return 0;
}




