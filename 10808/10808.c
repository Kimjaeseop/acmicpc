#include <stdio.h>
#include <string.h>

int arr[26];
char input[101];

int main(void)
{
	scanf("%s", input);

	for (int i=0; i<strlen(input); i++)
		arr[input[i]-'a']++;

	for (int i=0; i<26; i++)
		printf("%d ", arr[i]);

	return 0;
}
