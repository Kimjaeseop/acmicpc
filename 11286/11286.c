#include <stdio.h>

int N, S, in;
int arr[200001];

/* 절댓값 힙
   이것저것 경우의 수 처리, 예외 처리가 복잡했다
   짜고보면 별거 아닌데,,

   구현하고 다른 사람 코드보니까 pair로 (절댓값, 원래 값)을 넣어서 절댓값 우선으로 정렬하면 그냥 완성이다
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

	if (S % 2 == 0 && (n * 2) == S) // 터미널노드가 하나일 때
		idx = n * 2;

	if (idx > S) // 자식 인덱스를 계산했을때, 사이즈를 넘어서면 함수 종료
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

