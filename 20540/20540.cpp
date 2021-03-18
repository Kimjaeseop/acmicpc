#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	string in;
	map<char, string> m;
	m['E'] = "I";
	m['I'] = "E";
	m['S'] = "N";
	m['N'] = "S";
	m['T'] = "F";
	m['F'] = "T";
	m['J'] = "P";
	m['P'] = "J";

	cin >> in;

	for (char c : in)
		cout << m[c];

	cout << endl;
		
	return 0;
}
