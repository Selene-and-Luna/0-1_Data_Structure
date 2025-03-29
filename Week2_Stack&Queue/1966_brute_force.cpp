#include <iostream>
#include <queue>
using namespace std;

// 완전탐색(브루트포스)를 이용한 풀이
// 참조:https://kokodakadokok.tistory.com/entry/%EB%B0%B1%EC%A4%80-1966%EB%B2%88-%ED%94%84%EB%A6%B0%ED%84%B0-%ED%81%90-C-%ED%92%80%EC%9D%B4
int main(void){	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			q.push({p, i}); // 문서의 중요도, 해당 문서가 몇번째인지 
		}
		int result = 1;
		while(1) {
			int maximum = -0x7fffffff;
			for (int i = 0; i < q.size(); i++) {
				int p = q.front().first;
				int nth = q.front().second;
				maximum = max(maximum, p);
				q.pop();
				q.push({p, nth});
			}
			int p = q.front().first;
			int nth = q.front().second;
			if (p != maximum) {
				q.pop();
				q.push({p, nth});
			}
			else {
				if (nth == m) break;
				else {
					q.pop();
					result++;
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}
