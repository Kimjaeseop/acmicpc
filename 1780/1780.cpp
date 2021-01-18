#include <iostream>
#include <queue>

using namespace std;

typedef struct _NODE {
	int X, Y, T;
} NODE;

int N;
int arr[4096][4096];
int ans[3];
queue<NODE> Q;

int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	Q.push({0, 0, N});

	while (!Q.empty()) {
		int chk = 0;
		NODE T_NODE = Q.front();
		Q.pop();

		for (int i = 0; (i < T_NODE.T) && !chk; i++) {
			for (int j = 0; j < T_NODE.T; j++) {
				if (arr[i + T_NODE.X][j + T_NODE.Y] != arr[T_NODE.X][T_NODE.Y]) {
					chk = 1;

					for (int p = 0; p < 3; p++) {
						Q.push({T_NODE.X + ((T_NODE.T/3) * p),
								T_NODE.Y,
								T_NODE.T/3});
						Q.push({T_NODE.X + ((T_NODE.T/3) * p),
								T_NODE.Y + (T_NODE.T/3),
								T_NODE.T/3});
						Q.push({T_NODE.X + ((T_NODE.T/3) * p),
								T_NODE.Y + (T_NODE.T/3) * 2,
								T_NODE.T/3});
					}
					break;
				}
			}
		}

		if (chk == 0) {
			ans[arr[T_NODE.X][T_NODE.Y] + 1]++;
		}
	}

	for (int i = 0; i < 3; i++)
		cout << ans[i] << endl;

	return 0;
}
