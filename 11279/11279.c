#include <stdio.h>

int arr[200001];
int N, S, in;

void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// top - down
void heap_delete(int n)
{
	// 두 개의 자식 노드 중 큰 값을 가진 트리의 인덱스를 가져옴
	int idx = arr[n * 2] > arr[n * 2 + 1] ? (n * 2) : (n * 2 + 1); 

	// 큰 자식을 부모의 위치와 바꿈
	if (arr[n] < arr[idx]) {
		swap(n, idx);
		heap_delete(idx);
	}
}

// bottom - up
void heap_insert(int n)
{
	if (n <= 1) {
		return ;
	}

	// 위로 올라가면서 자식이 더 큰 값을 가지고 있다면 부모와 위치를 바꾸는 재귀 구조
	if (arr[n] > arr[n / 2]) {
		swap(n, n / 2);
		heap_insert(n / 2);
	}
}


int main(void)
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &in);

		if (in == 0) {
			printf("%d\n", arr[1]);

			if (S != 0) {
				arr[1] = 0;

				swap(1, S--); // pop 할 때 root를 pop하고 가장 최근에 들어온 값과 위치를 바꿈
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
