#include<iostream>
#include <algorithm>
using namespace std;
int w;
int n;
int p[40001];
int main() {
	cin >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	int ans = 0;
	sort(&p[1], &p[n + 1]);
	for (int i = 1, j = n; i <= j;) {
		if (p[i] + p[j] <= w) {
			i++;
			j--;
			ans++;
		}
		else {
			j--;
			ans++;
		}
	}
	cout << ans << endl;
}