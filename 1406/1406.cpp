#include <iostream>
#include <stack>

using namespace std;

// 커서를 두 개의 스택으로 생각하다니 정말 대단해
stack <char> L;
stack <char> R;

int M;
char c;
char str[600001];

int main(void)
{
	//freopen("./input/editor.in1", "r", stdin);
	//freopen("input3.txt", "r", stdin);
	// 이 문제는 정말 개행 아스키가 열받았다
	while ((c = getchar())!='\n')
		L.push(c);

	scanf("%d\n", &M);

	for (int i=0; i<M; i++) {
		scanf("%c", &c);

		if (c=='L' && L.size()!=0) {
			R.push(L.top());
			L.pop();
		}
		else if (c=='D' && R.size()!=0) {
			L.push(R.top());
			R.pop();
		}
		else if (c=='B' && L.size()!=0) {
			L.pop();
		}
		else if (c=='P') {
			getchar();
			c = getchar();

			L.push(c);
		}
		getchar();
	}

	int L_size = L.size();

	while (L.size()) {
		str[L.size()-1] = L.top();
		L.pop();
	}

	while (R.size()) {
		str[L_size++] = R.top();
		R.pop();
	}

	printf("%s\n", str);

	return 0;
}

