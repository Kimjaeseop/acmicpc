#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int input=0;
	int std=1000000;
	int num=0;
	int j=0;

	scanf("%d", &input);

	for (int i=1; i<1000001; i++) {
		j=i;
		while (j<std)
			std/=10;

		num = j;

		while (j) {
			num += j/std;
			j%=std;
			std /= 10;
		}

		if (input == num) {
			printf("%d\n", i);
			return 0;
		}
			
		std=1000000;
		num=0;
	}

	printf("0\n");

	return 0;
}
