#include <stdio.h>
#include <stdbool.h>

// time over

int T, n;
bool check[100001];
int arr[100001];
int cnt, ANS;

bool DFS(int root, int num, int depth)
{
	if (check[arr[num]] == false) {
		check[arr[num]] = true;

		if (arr[arr[num]] != root) {
			check[arr[num]] = DFS(root, arr[num], depth + 1);
		}
		else {
			ANS -= (depth + 1);
		}

		return check[arr[num]];
	}

	return false;
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		cnt = 0;
		ANS = n;

		for (int i = 1; i <= n; i++) {
			check[i] = arr[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);

			if (arr[i] == i) {
				check[i] = true;
				ANS -= 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				check[i] = true;
				check[i] = DFS(i, i, 1);
			}
		}

		printf("%d\n", ANS);
	}

	return 0;
}
