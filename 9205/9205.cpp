#include <cstdio>
#include <unistd.h>

int t, n;

typedef struct {
	short x, y;
} NODE;

NODE home, fest;
NODE cvs[101];

bool success;

short abs(short N)
{
	return N > 0 ? N : -N;
}

void DFS(NODE prevLocate, int depth, int curDistance)
{
	int curLocate = abs(prevLocate.x-cvs[depth].x) + abs(prevLocate.y-cvs[depth].y);
	int nextDistance = curDistance + curLocate;

	printf("prev x : %hd, prev y : %hd\n", prevLocate.x, prevLocate.y);
	printf("cur x : %hd, cur y : %hd, nextDistance : %d\n", cvs[depth].x, cvs[depth].y, nextDistance);

	sleep(1);

	if (depth == n) {
		if (nextDistance <= 1000)
			success = true;

		return ;
	}
	
	if (nextDistance <= 1000) {
		nextDistance -= (curLocate - (curLocate % 50));
		DFS(cvs[depth], depth + 1, nextDistance);
	}

	DFS(prevLocate, depth + 1, curDistance);
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);
	scanf("%d", &t);

	while (t--) {
		success = false;
		scanf("%d", &n);

		scanf("%hd %hd", &(home.x), &(home.y));

		for (int i = 0; i < n; i++) {
			scanf("%hd %hd", &(cvs[i].x), &(cvs[i].y));
		}

		scanf("%hd %hd", &(cvs[n].x), &(cvs[n].y));

		NODE prevLocate = {home.x, home.y};
		int curLocate = abs(prevLocate.x-cvs[n].x) + abs(prevLocate.y-cvs[n].y);

		if (curLocate <= 1000) {
			printf("happy\n");
			continue;
		}

		DFS(prevLocate, 0, 0);
		success == true ? printf("happy\n") : printf("sad\n");

	}
	return 0;
}
