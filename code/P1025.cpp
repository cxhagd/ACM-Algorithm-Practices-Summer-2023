#include<iostream>
using namespace std;
int n, k;
int cnt = 0;

void dfs(int last, int fin, int sum) {
	if (fin == k) {
		if (sum==n) {
			cnt++;
		  }
		return;
	}
	for (int i = last; sum+i*(k-fin)<=n; i++) {

		dfs(i, fin + 1, sum + i);
	}


}
int main() {
	cin >> n >> k;

	dfs(1,0,0);

	cout << cnt << endl;
}