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

	if (t[N].check == true) { // �̹� ã�Ҵ� ����� ? ���ڰ� ó�� ���� ��ġ�� ��ȯ
		return t[N].cnt;
	}

	t[N].check = true; // node init
	t[N].cnt = cnt;

	num = N;

	while (num) { // ���� ���ڸ��� �����ϸ� ����
		tmp = num % 10;
		t[N].val += (int)pow((double)tmp, (double)P);
		num /= 10;
	}

	return func(t[N].val, cnt + 1); // ���� ���� ��ͷ� �ѱ�
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &A, &P);
	
	printf("%d\n", func(A, 0));

	return 0;
}



