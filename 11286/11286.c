#include <stdio.h>

int N, S, in;
int arr[200001];

/* ���� ��
   �̰����� ����� �� ó��, ���� ó���� �����ߴ�
   ¥���� ���� �ƴѵ�,,

   �����ϰ� �ٸ� ��� �ڵ庸�ϱ� pair�� (����, ���� ��)�� �־ ���� �켱���� �����ϸ� �׳� �ϼ��̴�
*/

void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void heap_delete(int n)
{
	int idx;
	int n_1 = arr[n * 2] < 0 ? -arr[n * 2] : arr[n * 2];
	int n_2 = arr[n * 2 + 1] < 0 ? -arr[n * 2 + 1] : arr[n * 2 + 1];

	if (n >= S)
		return ;

	idx = n_1 > n_2 ? (n * 2 + 1) : n_1 == n_2 ? ((arr[n * 2] > arr[n * 2 + 1]) ? n * 2 + 1 : n * 2) : n * 2;

	if (S % 2 == 0 && (n * 2) == S) // �͹̳γ�尡 �ϳ��� ��
		idx = n * 2;

	if (idx > S) // �ڽ� �ε����� ���������, ����� �Ѿ�� �Լ� ����
		return ;

	n_1 = arr[n] < 0 ? -arr[n] : arr[n];
	n_2 = arr[idx] < 0 ? -arr[idx] : arr[idx];

	if (n_1 > n_2 || (n_1 == n_2 && (arr[n] > arr[idx]))) {
		swap(n, idx);
		heap_delete(idx);
	}
}

void heap_insert(int n)
{
	if (n <= 1) {
		return ;
	}

	int n_1 = arr[n] < 0 ? -arr[n] : arr[n];
	int n_2 = arr[n / 2] < 0 ? -arr[n / 2] : arr[n / 2];

	if (n_1 < n_2 || (n_1 == n_2 && (arr[n] < arr[n / 2]))) {
		swap(n, n / 2);
		heap_insert(n / 2);
	}
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &in);

		if (in == 0) {
			printf("%d\n", arr[1]);

			if (S != 0) {
				arr[1] = 0;

				swap(1, S--);
				heap_delete(1);
			}
		}
		else {
			arr[++S] = in;

			heap_insert(S);
		}
	}

	return 0;
}

