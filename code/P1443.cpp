#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

long long int ans = 0;
int a, b;
bool flag[9][9];
int movx[5] = { 0,-1,1,0,0 };
int movy[5] = { 0,0,0,1,-1 };

void dfs(int x, int y) {
	if (x==0 || y==0 || x == a || y == b) {
		ans++;
		return;
	}
	flag[x][y] = 1;
	for (int i = 1; i <=4; i++) {
		int xx = x + movx[i], yy = y + movy[i];
		if (flag[xx][yy]) {
			continue;
		}
		dfs(xx, yy);
	}
	flag[x][y] = 0;
	return;
}

int main() {
	cin >> a >> b;
   
 for (int i = 1; i <a; i++) {
		flag[i][0] = 1;
		dfs(i, 1);
		flag[i][0] = 0;
	}
	for (int i = 1; i <b; i++) {
		flag[0][i] = 1;
		dfs(1, i);
		flag[0][i] = 0;
	}
	cout << ans << endl;
}
