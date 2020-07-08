#include <stdio.h>
#include <stdlib.h>

// 이분 탐색, lower bound, upper bound

int N, M;
int tmp;
int arr[500001];

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int lower_bound(int t) // 원하는 값 "이상"의 값이 처음 나오는 위치
{
    int l, r, mid;

    l = 1;
    r = N + 1; 

    while (r > l) {
        mid = (r + l) / 2;

        if (arr[mid] >= t) { // "이상"이기 때문에 타겟을 포함한 이상의 범위엔 r = mid
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return r;
}

int upper_bound(int t) // 원하는 값 "초과"의 값이 처음 나오는 위치
{
    int l, r, mid;

    l = 1;
    r = N + 1; // N + 1이 아닌 N을 넣어주면 가장 큰 값은 N이 return 되기 때문에 초과한 값이 아님

    while (r > l) {
        mid = (r + l) / 2;

        if (arr[mid] > t) { // "초과"이기 때문에 타겟을 포함하지 않은 초과의 범위에 r = mid
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

