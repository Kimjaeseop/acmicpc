#include <stdio.h>

#define WHEELNUM 4
#define TOOTHNUM 8
#define LEFTTOOTH 7
#define RIGHTTOOTH 3

int inputArr[6][10];
int curLocation[4];

int getToothIndex(int direction, int wheelIndex)
{
	int toothIndex = direction + curLocation[wheelIndex];

	return toothIndex > TOOTHNUM ? toothIndex % TOOTHNUM : toothIndex;
}

void moveIndex(int wheelIndex, int direction)
{
	if (direction == -1) {
		curLocation[wheelIndex] = (curLocation[wheelIndex] + 1) % 8;
	}
	else {
		curLocation[wheelIndex] = (curLocation[wheelIndex] + 7) % 8;
	}
}

void moveLeft(int wheelIndex, int direction)
{
	if (wheelIndex < 1) {
		return ;
	}

	if (inputArr[wheelIndex][getToothIndex(RIGHTTOOTH, wheelIndex)] 
			!= inputArr[wheelIndex+1][getToothIndex(LEFTTOOTH, wheelIndex+1)]) {
		moveLeft(wheelIndex-1, -direction);
		moveIndex(wheelIndex, direction);
	}
}

void moveRight(int wheelIndex, int direction)
{
	if (wheelIndex > WHEELNUM) {
		return ;
	}

	if (inputArr[wheelIndex][getToothIndex(LEFTTOOTH, wheelIndex)] 
			!= inputArr[wheelIndex-1][getToothIndex(RIGHTTOOTH, wheelIndex-1)]) {
		moveRight(wheelIndex+1, -direction);
		moveIndex(wheelIndex, direction);
	}
}

void move(int wheelIndex, int direction)
{
	moveLeft(wheelIndex-1, -direction);
	moveRight(wheelIndex+1, -direction);
	moveIndex(wheelIndex, direction);
}


int main(void)
{
	int K, n, d, ANS;

	freopen("input_4.txt", "r", stdin);

	K = n = d = ANS = 0;

	for (int i = 1; i <= WHEELNUM; i++) {
		for (int j = 1; j <= TOOTHNUM; j++) {
			scanf("%1d", &inputArr[i][j]);
		}
	}

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &n, &d);
		move(n, d);
	}

	for (int i = 1; i <= WHEELNUM; i++) {
		if (inputArr[i][getToothIndex(1, i)] == 1) {
			ANS += (1 << (i-1));
		}
	}

	printf("%d", ANS);

	return 0;
}


