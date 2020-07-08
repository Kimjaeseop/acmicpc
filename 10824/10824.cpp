#include <stdio.h>
#include <string>

using namespace std;

int A, B, C, D;
char sum_AB[15];
char sum_CD[15];

int main(void)
{
	scanf("%d %d %d %d", &A, &B, &C, &D);

	sprintf(sum_AB, "%d%d", A, B);
	sprintf(sum_CD, "%d%d", C, D);

	string tmp1(sum_AB); // char* to string
	string tmp2(sum_CD);
	
	printf("%lld\n", stoll(tmp1) + stoll(tmp2)); // string to long long

	return 0;
}

