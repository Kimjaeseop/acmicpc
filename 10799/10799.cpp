#include <stdio.h>
#include <string.h>

char input[100001];
int ans;
int tmp;

int main(void)
{
	freopen("input.txt", "r", stdin);

	//scanf("%s", input);

	int c;
	for (int i=0; c != '\n'; i++) {
		c = getchar(); // 한문자씩 받지 않으면 O(n)이기 때문에 시간초과
		input[i]=(char)c;

		if (input[i]=='(')	
			tmp++;
		else if (input[i]==')'){
			tmp--;
			if (input[i-1]=='(')
				ans += tmp;
			else
				ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
