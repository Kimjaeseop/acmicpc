#include <iostream>
#include <vector>
#include <utility>

#include <unistd.h>

using namespace std;

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int MIN = 2100000000;

typedef struct {
	int y;
	int x;
} node;

node shark;

int isPossible(int arr[22][22], int n) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > n)
				return 1;
		}
	}

	return -1;
}

void DFS(node cur, int arr[22][22], pair<int, int> p, int cnt) {
	node next;
	int tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "cnt : " << cnt << endl;
	for (int i = 0; i < 4; i++) {
		next.y = cur.y + dir[i][0];
		next.x = cur.x + dir[i][1];

		if (arr[next.y][next.x] < p.first) {
			tmp = arr[next.y][next.x];
			arr[next.y][next.x] = 0;

			p.second++;
			if (p.second == p.first) {
				p.first++;
				p.second = 0;
			}

			if (isPossible(arr, p.first) == 1) {
				DFS(next, arr, p, cnt++);
				arr[next.y][next.x] = tmp;
			}
			else {
				if (MIN > cnt)
					MIN = cnt;
			}
		}
		else if (arr[next.y][next.x] == p.first) {
			if (isPossible(arr, p.first) == 1)
				DFS(next, arr, p, cnt++);
		}
	}
}

int main(void)
{
	int in;
	int arr[22][22] = {{0,},};

	freopen("input_1.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 9) {
				shark.y = i;
				shark.x = j;
			}
		}
	}

	DFS({0, 0}, arr, {2, 0}, 0);

	cout << MIN << endl;

	return 0;
}
