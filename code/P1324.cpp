#include<iostream>
#include<algorithm>
using namespace std;
long long int ans = 0;
int N, M;
int n[2011], m[2011];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N-1; i++) {
		cin >> n[i];
	}
	for (int i = 1; i <= M-1; i++) {
		cin >> m[i];
	}
	int p1 = 1;
	int p2 = 1;
	sort(&n[1], &n[N ], cmp);
	sort(&m[1], &m[M], cmp);
	for (int i=0; i<=N-1+M-1;i++) {
		if (n[p1] > m[p2]) {
			ans += n[p1++] * p2;
			
		}
		else {
			ans += m[p2++] * p1;
			
		}
	}
	cout << ans << endl;



}