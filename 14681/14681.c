#include <stdio.h>

int x, y, ans;

int main(void)
{
	scanf("%d %d", &x, &y);

	if(x > 0) {
		if(y > 0) {
			ans = 1;
		}
		else {
			ans = 4;
		}
	}
	else {
		if (y > 0) {
			ans = 2;
		}
		else {
			ans = 3;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}
