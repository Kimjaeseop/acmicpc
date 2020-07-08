#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int sub1;
	int sub2;
	int sub3;
	char name[11];
} input;

input arr[100001];

int ret_alpha (char alpha) {
	if ((int)alpha - 'a' >= 0)
		return (int)alpha-'a';
	else
		return (int)alpha-'A';
}

int compare (const void *a, const void *b)
{
	input tmp1 = *(input *)a;
	input tmp2 = *(input *)b;

	// 국 == 영 == 수
	if (tmp1.sub1==tmp2.sub1 && tmp1.sub2==tmp2.sub2 && tmp1.sub3==tmp2.sub3) {
		if (strcmp(tmp1.name, tmp2.name)>0)
			return 1;
		else
			return -1;
	} // 국 == 영
	else if (tmp1.sub1==tmp2.sub1 && tmp1.sub2==tmp2.sub2) {
		if (tmp1.sub3<tmp2.sub3)
			return 1;
		else
			return -1;
	} // 국
	else if (tmp1.sub1==tmp2.sub1) {
		if (tmp1.sub2>tmp2.sub2)
			return 1;
		else
			return -1;
	} 
	else {
		if (tmp1.sub1<tmp2.sub1)
			return 1;
		else
			return -1;
	}

	return 0;
}

int main(void)
{
	int N;

	//freopen("input.txt", "r", stdin);

	scanf("%d\n", &N);

	for (int i=0; i<N; i++) {
		scanf("%s %d %d %d", arr[i].name, &(arr[i].sub1), &(arr[i].sub2), &(arr[i].sub3));
	}

	qsort (arr, N, sizeof(input), compare);

	for (int i=0; i<N; i++)
		printf("%s\n", arr[i].name);

	return 0;
}
