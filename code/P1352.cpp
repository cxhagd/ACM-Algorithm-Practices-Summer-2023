#include<iostream>
#include<vector> 
using namespace std;
int n;
int r[6000 + 11];
int f[6000 + 11][2];
vector<int> son[6000 + 11];
bool vi[6000 + 11];
int root, ans;
void dp(int x) {
	f[x][0] = 0;
	f[x][1] = r[x];
	for (int i = 0; i < son[x].size(); i++) {
		int y = son[x][i];
		dp(y);
		f[x][0] += max(f[y][0], f[y][1]);
		f[x][1] += f[y][0];
	}



}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int x,y;
		cin >> x >> y;
		son[y].push_back(x);
		vi[x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!vi[i]) {
			root = i;
			break;
		}
	}
	dp(root);
	cout << max(f[root][0], f[root][1]) << endl;
}