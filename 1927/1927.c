#include <stdio.h>

int N, S, in;
int arr[200001];

void swap(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heap_delete(int n)
{
    int idx = arr[n * 2] >= arr[n * 2 + 1] ? (n * 2 + 1) : (n * 2);

	// �� �κ��� �����ϰ�� max heap�� ������ ����
    if (n > S || (n * 2) > S || (n * 2 + 1) > S) { // Ʈ������ ����� üũ�ϴ� ���
		// ��尡 �� ���� ��� �͹̳� ����� ������ ���� ������ �������
		// ��Ʈ���� �ϳ��� �͹̳� ���� �񱳰� �����ϹǷ� �� �� ����
        if ((n * 2) <= S && arr[n] > arr[n * 2]) { 
            swap(n, n * 2);
        }
        return ;
    }

    if (arr[n] > arr[idx]) {
        swap(n, idx);
        heap_delete(idx);
    }
}

void heap_insert(int n)
{
    if (n <= 1) {
        return ;
    }

    if (arr[n] < arr[n / 2]) {
        swap(n, n / 2);
        heap_insert(n / 2);
    }
}

int main(void)
{
    //freopen("input2.txt", "r", stdin);

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

        /*
        printf("========================\n");

        for (int i = 1; i <= S; i++) {
            printf("%d\n", arr[i]);
        }

        printf("========================\n");
        */
    }

    return 0;
}

