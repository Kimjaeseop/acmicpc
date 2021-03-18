#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main(void)
{
	map<string, double> m;
	m["A+"] = 4.3;
	m["A0"] = 4.0;
	m["A-"] = 3.7;
	m["B+"] = 3.3;
	m["B0"] = 3.0;
	m["B-"] = 2.7;
	m["C+"] = 2.3;
	m["C0"] = 2.0;
	m["C-"] = 1.7;
	m["D+"] = 1.3;
	m["D0"] = 1.0;
	m["D-"] = 0.7;
	m["F"] = 0.0;

	string in;

	cin >> in;
	// 소수점 한자리 수만 출력해야 정답
	// cout으로 제출하면 오답 ...

	printf("%.1f\n", m[in]);

	return 0;
}
