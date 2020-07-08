#include <stdio.h>

int N;
int arr[130][130];
int bl, wh; // blue, white
int bl_ck, wh_ck;

void BFS(int l, int r, int t, int b) // 왼쪽, 오른쪽, 위, 아래
{
	if (l > r || t > b) {
		return ;
	}

	bl_ck = wh_ck = 0;

	for (int i = l; i <= r; i++) {
		for (int j = t; j <= b; j++) {
			if(arr[i][j] != 1 && !bl_ck) {
				bl_ck = 1;
			}
			else if(arr[i][j] != 0 && !wh_ck) {
				wh_ck = 1;
			}

			if(wh_ck && bl_ck) {
				break;
			}
		}
	}

	if(!bl_ck) {
		bl++;
	}

	if(!wh_ck) {
		wh++;
	}

	if(bl_ck && wh_ck) {
		BFS(l, (l + r)/2, t, (t + b)/2); BFS((l + r)/2 + 1, r, t, (t + b)/2);
		BFS(l, (l + r)/2, (t + b)/2 + 1, b); BFS((l + r)/2 + 1, r, (t + b)/2 + 1, b);
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

	BFS(1, N, 1, N);

	printf("%d\n%d", wh, bl);

	return 0;
}
