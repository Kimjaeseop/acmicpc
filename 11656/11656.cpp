#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1001];
char arr[2000][1001];

// ���ĺ��� ���ؼ� a�� ũ�� ���
// ������ 0, b�� ũ�� ������ ����
int compare(const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b); 
}

int main(void)
{
	scanf("%s", input);

	for (int i=0; i<strlen(input); i++) { // ���ڿ� ī��
		for (int j=i; j<strlen(input); j++)
			arr[i][j-i] = input[j];
	}

	qsort(arr, strlen(input), sizeof(input), compare); // ����

	for (int i=0; i<strlen(input); i++) // ���� �� ���
		printf("%s\n", arr[i]); 

	return 0;
}
