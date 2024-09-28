#include<iostream>
using namespace std;
bool temp[7][7] = { 1 };
bool obs[7][7] = { 1 };
int N, M, T;
int sx, sy, fx, fy;
int ans = 0;
int movx[5] = { 0,0,0,-1,1 };
int movy[5] = { 0,-1,1,0,0 };

void search(int x, int y) {
	if (x == fx && y == fy) {
		ans++;
		return;
	}
	else {
		for (int i = 1; i <= 4; i++) {//上下左右 
			if (temp[x + movx[i]][y + movy[i]] == 1 && obs[x + movx[i]][y + movy[i]] == 1) {
				temp[x][y] = 0;
				search(x + movx[i], y + movy[i]);
				temp[x][y] = 1;
			}

		}

	}
}

int main() {
	
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			obs[i][j] = 1;
			temp[i][j] = 1;
		}
	}

	cin >> sx >> sy >> fx >> fy;
	for (int i = 1; i <= T; i++) {
		int x, y;
		cin >> x >> y;
		obs[x][y] = 0;
	}
	
	temp[sx][sy] = 0;
	search(sx, sy);

	cout << ans << endl;
}