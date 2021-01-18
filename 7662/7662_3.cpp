#include <iostream>
#include <set>

// multiset은 삽입과 동시에 정렬된다. - 트리구조
// 때문에 검색, 삽입, 삭제 등 속도가 빠름
// 중복 허용
// element삽입 후 변경 불가

// greater -- 내림차순 ,, 헷갈리네

// 우선순위 큐 두개를 써도 안되고, deque를 써도 안되서 결국 검색해서 풀었다
// stl에 set과 multiset이 있는데 이 경우엔 중복을 허용하기 때문에 multiset 사용


using namespace std;

int T, k, N;
char C;

int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	
    multiset<int, less<int>> s;
	s.insert(1);
	cout << *(s.end()) << " " << *(--s.end()) << endl;
	s.insert(20);
	cout << *(s.end()) << " " << *(--s.end()) << endl;
	s.insert(30);
	cout << *(s.end()) << " " << *(--s.end()) << endl;
	s.insert(40);
	cout << *(s.end()) << " " << *(--s.end()) << endl;
	s.insert(50);
	cout << *(s.end()) << " " << *(--s.end()) << endl;
	s.insert(60);
	cout << *(s.end()) << " " << *(--s.end()) << endl;

	while (1);

    //freopen("input.txt", "r", stdin);

    cin >> T;

    while (T--) {
        multiset<int, less<int>> s;
        cin >> k;

        while (k--) {
            cin >> C >> N;

            if (C == 'I') {
                s.insert(N);
            }
            else if (C == 'D' && !s.empty()){
                N == -1 ? s.erase(s.begin()) : s.erase(--s.end());
            }
        }

        if (s.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << *(--s.end()) << " " << *(s.begin()) << "\n";
        }
    }

    return 0;
}
