#include <stdio.h>
#include <stdlib.h>

// �̺� Ž��, lower bound, upper bound

int N, M;
int tmp;
int arr[500001];

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int lower_bound(int t) // ���ϴ� �� "�̻�"�� ���� ó�� ������ ��ġ
{
    int l, r, mid;

    l = 1;
    r = N + 1; 

    while (r > l) {
        mid = (r + l) / 2;

        if (arr[mid] >= t) { // "�̻�"�̱� ������ Ÿ���� ������ �̻��� ������ r = mid
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return r;
}

int upper_bound(int t) // ���ϴ� �� "�ʰ�"�� ���� ó�� ������ ��ġ
{
    int l, r, mid;

    l = 1;
    r = N + 1; // N + 1�� �ƴ� N�� �־��ָ� ���� ū ���� N�� return �Ǳ� ������ �ʰ��� ���� �ƴ�

    while (r > l) {
        mid = (r + l) / 2;

        if (arr[mid] > t) { // "�ʰ�"�̱� ������ Ÿ���� �������� ���� �ʰ��� ������ r = mid
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return r;
}

// -10 -10 2 3 3 6 7 10 10 10
// 0   1   2 3 4 5 6 7  8  9
int main(void)
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort((arr+1), N, sizeof(int), comp);

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &tmp);

        printf("%d ", upper_bound(tmp) - lower_bound(tmp));
    }

    return 0;
}

