#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

int main(void)
{
	stack<int> A;
	stack<int> B;
	stack<int> C;

	int p, q;

	bool chk_A = 0;
	bool chk_B = 0;

	char str1[10000002];
	char str2[10000002];
	char ANS[10000002]={0,};
	scanf("%s %s", str1, str2);

	for (int i=strlen(str1)-1; i>0; i--) {
		if (i==0 && str1[0]=="-")
			chk_A=1;
		else
			A.push(str1[i]);
	}

	for (int i=strlen(str2)-1; i>0; i--)
		if (i==0 && str2[0]=="-")
			chk_B=1;
		else
			B.push(str2[i]);

	if (chk_A==0 && chk_B==0) {
		while (1) {
			if (A.size()>0) {
				p=A.top();
				A.pop();
			}
			else
				p=0;

			if (B.size()>0) {
				q=B.top();
				B.pop();
			}
			else
				q=0;



			if (A.size()==0 && B.size()==0)
				break;
		}

		for (int i=0; C.size()>0; i++) {
			ANS[i]=C.top()-"0";
			C.pop();
		}
	}

	printf("%s\n", ANS);

	return 0;
}
