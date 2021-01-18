#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char str[20000][51];

int compare(const void *a, const void *b) 
{
	if (strlen((char *)a) > strlen((char *)b)) // 길이 오름차순 // a > b : return 1;
		return 1;
	if (strlen((char *)a) < strlen((char *)b))
		return -1;									

	return strcmp((char*)a, (char*)b);
	// 이차원 포인터로 넘어온다
	// 그럼 *a는 스트링 하나라고 생각하면 편함
}
int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%s", str[i]);
		str[i][strlen(str[i])]='\0'; // null 안넣어주면 정렬 안된다 
	}

	qsort(str, N, sizeof(str[0]), compare);

	for (int i=0; i<N; i++) {
		if (strcmp(str[i], str[i+1]))
			printf("%s\n", str[i]);
	}

	return 0;
}
