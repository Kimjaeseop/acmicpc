#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

typedef struct _NODE {
	int X, Y;
} NODE;

char arr[128][128];
char str[128];
int N, M, K, str_len, depth, Q_size;

queue<NODE> Q;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	for (int i = 5; i < N+5; i++) {
		for (int j = 5; j < N+5; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> str;

	str_len = strlen(str);

	for (int i = 5; i < N+5; i++) {
		for (int j = 5; j < N+5; j++) {
			if (arr[i][j] == str[0]) {
				Q.push({i, j});
			}
		}
	}

	depth = 0;

	while (depth < (str_len-1)) {
		depth++;

		cout << "str : " << str[depth] << endl;

		Q_size = Q.size();

		for (int s = 0; s < Q_size; s++) {
			NODE t_node = Q.front();

			for (int i = 1; i <= K; i++) {
				if ((str[depth] == arr[t_node.X + i][t_node.Y]) ) {
					Q.push({t_node.X + i, t_node.Y});
				}

				if ((str[depth] == arr[t_node.X - i][t_node.Y])) {
					Q.push({t_node.X - i, t_node.Y});
				}

				if ((str[depth] == arr[t_node.X][t_node.Y + i])) {
					Q.push({t_node.X, t_node.Y + i});
				}

				if ((str[depth] == arr[t_node.X][t_node.Y - i])) {
					Q.push({t_node.X, t_node.Y - i});
				}
			}

			Q.pop();
		}
	}

	cout << Q.size() << endl;

	return 0;
}
