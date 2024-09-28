#include<iostream>
#include<cstring>
using namespace std;
struct point {
	int x;
	int y;
};
point b;
point hor;
bool obs[25][25];

long long ans = 0;


long long int f[25][25];

int main() {
	memset(obs, 1, sizeof(obs));

	cin >> b.x >> b.y >> hor.x >> hor.y;
	b.x++; b.y++; hor.x++; hor.y++;
	obs[hor.x][hor.y] = 0;

	if (hor.x - 1 >= 1 && hor.y - 2 >= 1) {
		obs[hor.x - 1][hor.y - 2] = 0;
	}
	if (hor.x - 2 >= 1 && hor.y - 1 >= 1) {
		obs[hor.x - 2][hor.y - 1] = 0;
	}
	if (hor.x + 1 >= 1 && hor.y - 2 >= 1) {
		obs[hor.x + 1][hor.y - 2] = 0;
	}
	if (hor.x + 2 >= 1 && hor.y - 1 >= 1) {
		obs[hor.x + 2][hor.y - 1] = 0;
	}
	if (hor.x + 2 >= 1 && hor.y + 1 >= 1) {
		obs[hor.x + 2][hor.y + 1] = 0;
	}
	if (hor.x + 1 >= 1 && hor.y + 2 >= 1) {
		obs[hor.x + 1][hor.y + 2] = 0;
	}
	if (hor.x - 1 >= 1 && hor.y + 2 >= 1) {
		obs[hor.x - 1][hor.y + 2] = 0;
	}
	if (hor.x - 2 >= 1 && hor.y + 1 >= 1) {
		obs[hor.x - 2][hor.y + 1] = 0;
	}
	if (obs[1][2] != 0) {
		f[1][2] = 1;
	}
	if (obs[2][1] != 0) {
		f[2][1] = 1;
	}
	for (int i = 1; i <= b.x; i++) {
		for (int j = 1; j <= b.y; j++) {
			if(obs[i][j] != 0)
			f[i][j] += f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[b.x][b.y] << endl;

}