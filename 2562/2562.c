#include <stdio.h>

int main(void)
{
	int in=0;
	int loc=0;
	int num=0;

	for (int i=0; i<9; i++) {
		scanf("%d", &in);
		if (in > num) {
			num=in;
			loc=i+1;
		}
	}

	printf("%d\n%d\n", num, loc);

	return 0;
}
			
		

