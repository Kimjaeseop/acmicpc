#include <stdio.h>

int N, M, r, c, d, countCallFunc;
int map[52][52], visit[52][52];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getOppositeDirection(int direction)
{
	switch(direction) {
		case 0:
			return 2;
		case 1:
			return 3;
		case 2: 
			return 0;
		case 3:
			return 1;
	}
}

void cleaning(int y, int x, int direction)
{
	int nextY, nextX, oppositeDirection, oppoY, oppoX, nextDirection;

	countCallFunc++;

	visit[y][x] = countCallFunc;
	nextDirection = direction;

	for (int i = 0; i < 4; i++) {
		// change direction to left
		nextDirection -= 1;
		if (nextDirection == -1) {
			nextDirection = 3;
		}

		// get next point
		nextY = y + dir[nextDirection][0];
		nextX = x + dir[nextDirection][1];

		// check Range
		if (nextY < 1 || nextX < 1 || nextY > N || nextX > M) {
			return ;
		}

		if (map[nextY][nextX] == 0 && visit[nextY][nextX] == 0) {
			cleaning(nextY, nextX, nextDirection);
			return ;
		}
	}

	oppositeDirection = getOppositeDirection(direction);
	oppoY = y + dir[oppositeDirection][0];
	oppoX = x + dir[oppositeDirection][1];

	if (oppoY < 1 || oppoX < 1 || oppoY > N || oppoX > M) {
		return ;
	}

	if (map[oppoY][oppoX] == 0) {
		countCallFunc--;
		cleaning(oppoY, oppoX, direction);

		return ;
	}

	return ;
}

int main(void)
{
	//freopen("input_2.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &(map[i][j]));
		}
	}

	cleaning(r+1, c+1, d);

	printf("%d\n", countCallFunc);

	return 0;
}
