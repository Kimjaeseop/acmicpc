#include <stdio.h>

// 시간 초과 이후 솔루션이 떠오르지 않아 검색
// 1 -> 3 -> 3 과 같이 Cycle을 찾지 못했는데도 이미 방문한 노드를 방문했다면
// 부분 싸이클  (3 -> 3)이 있는 것으로 간주해서
// 부분 싸이클의 길이를 반환

// 싸이클을 찾았다면
// 이미 방문한 노드 (싸이클이 완성되었기 때문에 이미 방문한 노드는 root노드)
// 를 현재 depth에서 빼주면 싸이클에 포함된 노드의 수가 나오는데
// 이를 반환해준다.

// check 배열을 지우지 않음으로 앞에서 이미 싸이클을 찾아서 체크했다면
// 두 번 계산되지 않음

int check[100001];
int start_node[100001];
int arr[100001];
int T, N, ANS;

int DFS(int root, int cur, int depth)
{
	if (check[cur]) {
		if (start_node[cur] != root) { // 이 경우는 뜬금없이 싸이클 중간에 있는 노드를 가르키는 경우의 처리
			return 0;
		}

		return depth - check[cur];
	}

	start_node[cur] = root;
	check[cur] = depth;

	return DFS(root, arr[cur], depth + 1);
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		ANS = 0;

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);

			check[i] = start_node[i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				ANS += DFS(i, i, 1);
			}
		}

		printf("%d\n", N - ANS);
	}

	return 0;
}
