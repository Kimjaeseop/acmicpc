#include <iostream>
#include <utility>
#include <queue>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// �׸���
int dir[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}; // 4���� �˰����� ���� ���� �迭
int arr[102][102]; // input array
int land_chk[102][102]; // ���� ����ȭ�� ���� �ʿ��� �迭

int ans, cnt;
int N;

queue <pair<int, int>> Q; // BFS�� ���� Queue

void DIV(int A, int B) // BFS�� ������ ����ȭ �˰���
{
	if (arr[A][B] == 1) {
		land_chk[A][B] = cnt;
	}

	for (int i = 0; i < 4; i++) {
		int Y = A + dir[i][0];
		int X = B + dir[i][1];

		if (Y < 1 || X < 1 || Y > N || X > N) {
			continue;
		}

		if (arr[Y][X] == 1 && land_chk[Y][X] == 0) {
			DIV(A + dir[i][0], B + dir[i][1]);
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	ans = 200; // ������ Minimum���̱� ������ 100 * 100���� ���� �� �ִ� ���� �ִ밪
	cnt = 1; // ���� ������ counting�� ����

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (land_chk[i][j] == 0 && arr[i][j] == 1) {
				DIV(i, j);
				cnt++; // ���� numbering�� ������ count�ϱ� ����
			}
		}
	}

	cnt -= 1; 

	for (int i = 1; i <= cnt; i++) {
		int sea_chk[102][102] = {0, }; // �湮�� ���� �ٴٸ� check

		while (!Q.empty()) {
			Q.pop(); // Queue init
		}

		for (int p = 1; p <= N; p++) {
			for (int q = 1; q <= N; q++) {
				if (land_chk[p][q] == i) {
					Q.push({p, q}); // BFS �غ� // �� ���� Queue�� �־� ó��
				}
			}
		}

		int escape = 0, depth = 0;
		// BFS�� depth Ȯ�ο� ������ while�� ���������� ���� escape ����

		while (!escape) { // �߰��� ���� ��� ���� ã���� ���� ������ escape ����
			int S = Q.size(); // BFS�� depth���� ó���ϱ� ���� ����
			depth++;

			if (depth > ans) { // Greedy �߰��� �̹� �ּҰ��� �Ѿ������ �ߴܽ�Ŵ
				break;
			}

			while (S-- && !escape) { // tree�� �̹� depth�� node��ŭ ���� �� escape ����
				int A = Q.front().first;
				int B = Q.front().second;

				Q.pop();

				for (int j = 0; j < 4; j++) {
					int Y = A + dir[j][0];
					int X = B + dir[j][1];

					if (Y < 1 || X < 1 || Y > N || X > N) { // ������ ��� ���
						continue;
					}

					if (sea_chk[Y][X] == 1) { // �̹� �湮�� ���
						continue;
					}

					if (i != land_chk[Y][X] && arr[Y][X] == 1) { // ���� ã�����
						escape = 1;
						break;
					}

					if (sea_chk[Y][X] == 0) { // BFS�� �߰��� �ٴ� �� ���� ��
						sea_chk[Y][X] = 1;
						Q.push({Y, X});
					}
				}
			}
		}
		if ((depth - 1) < ans) { // Minimum check
			ans = (depth - 1);
		}
	}

	printf("%d\n", ans);

	return 0;
}

