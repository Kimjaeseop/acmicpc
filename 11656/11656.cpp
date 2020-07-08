#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1001];
char arr[2000][1001];

// 알파벳을 비교해서 a가 크면 양수
// 같으면 0, b가 크면 음수를 리턴
int compare(const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b); 
}

int main(void)
{
	scanf("%s", input);

	for (int i=0; i<strlen(input); i++) { // 문자열 카피
		for (int j=i; j<strlen(input); j++)
			arr[i][j-i] = input[j];
	}

	qsort(arr, strlen(input), sizeof(input), compare); // 정렬

	for (int i=0; i<strlen(input); i++) // 정렬 후 출력
		printf("%s\n", arr[i]); 

	return 0;
}
