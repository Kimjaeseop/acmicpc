#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue <int> Q;
string in;
char out[2000000];
int SIZE;
int TOP;
char *t;

int main (void) 
{
	ios_base::sync_with_stdio(false);
	cin >> in;

	for (int i=0; i<in.size(); i++)
		Q.push(in[i]-'0');

	SIZE = Q.size();

	while (SIZE) {
		out[TOP++] = Q.front() & 4 ? '1' : '0';
		out[TOP++] = Q.front() & 2 ? '1' : '0';
		out[TOP++] = Q.front() & 1 ? '1' : '0';

		Q.pop();
		SIZE--;
	}

	out[TOP] = '\0';

	for (t = out; *t != '\0'; t++)
		if (*t == '1')
			break;

	/*
	if (*t=='\0')
		cout << 0 << endl;
	else
		cout << t << endl;
	*/

	cout << (*t=='\0' ? "0" : t) << endl;
	// "0"으로 한 이유는 0으로 정수형으로 하면 0번 (NULL) 주소에서 가져오려고 하기 때문에 오류
	// t가 포인터이기 때문에.

	return 0;
}






