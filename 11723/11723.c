#include <stdio.h>

int M;
int arr[21];
char str[7];
int num;

int main(void) {
	freopen("input.txt", "r", stdin);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%s", str);

		if(str[0] == 'e') {
			for (int j = 1; j <= 20; j++) {
				arr[j] = 0;
			}
		}
		else {
			scanf("%d", &num);

			if(str[0] == 'a') {
				if(str[1] == 'd') {
					arr[num]++;
				}
				else {
					for (int j = 1; j <= 20; j++) {
						arr[j] = 1;
					}
				}
			}
			else if(str[0] == 'r' && arr[num] != 0) {
				arr[num]--;
			}
			else if(str[0] == 'c') {
				printf("%d\n", arr[num] > 0 ? 1 : 0);
			}
			else if(str[0] == 't') {
				if (arr[num] == 0) {
					arr[num]++;
				}
				else {
					arr[num]--;
				}
			}
		}
	}

	return 0;
}
