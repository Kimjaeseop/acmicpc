#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int num=0;
	bool check[42]={0,};
	int cnt=0;

	//freopen("input1.txt", "r", stdin);

	for (int i=0; i<10; i++) {
		scanf("%d", &num);
		if(!check[num%42])
			check[num%42]=1;
		//printf("%d\n", num%42);
	}

	for (int i=0; i<42; i++) {
		if (check[i]) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
	
