#include <stdio.h>
#include <string.h>

int N;
char input[51];

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%s", input);
		int cnt=0;
		int ans=1;
		for (int j=0; j<strlen(input); j++) {
			if (input[j]=='(')
				cnt++;
			else
				cnt--;

			if (cnt<0) {
				ans=0;
				break;
			}
		}
		if (ans==0 || cnt!=0)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
