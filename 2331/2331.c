#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	bool check;
	int cnt;
	int val;
} node;

int A, P;
node t[250000];
int ans;

int func(int N, int cnt)
{
	int tmp = 0;
	int num = N;

	if (t[N].check == true) { // 이미 찾았던 수라면 ? 숫자가 처음 나온 위치를 반환
		return t[N].cnt;
	}

	t[N].check = true; // node init
	t[N].cnt = cnt;

	num = N;

	while (num) { // 수를 한자리씩 연산하며 저장
		tmp = num % 10;
		t[N].val += (int)pow((double)tmp, (double)P);
		num /= 10;
	}

	return func(t[N].val, cnt + 1); // 다음 수를 재귀로 넘김
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &A, &P);
	
	printf("%d\n", func(A, 0));

	return 0;
}



