#include<iostream>
using namespace std;


long long int n,T, h, r;
long long int fa[1111];
long long int x[1111], y[1111], z[1111];
long long int btm[1111], rof[1111];

bool bot(int i) {
	return(z[i] - r <= 0);
}
bool roo(int i) {
	return (z[i] + r >= h);
}

bool cont(int j, int i) {
	if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]) <= r * 2 * r * 2) {
		return 1;
	}
	else {
		return 0;
	}
}
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
int main() {
	cin >> T;
	for (int m = 1; m <= T; m++) {
	
		cin >> n >> h >> r;
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i] >> z[i];
		}
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		int nbtm = 0;
		int nrof = 0;
		for (int i = 1; i <= n; i++) {
			if (bot(i)) {
				nbtm++;
				btm[nbtm] = i;
			}
			if (roo(i)) {
				nrof++;
				rof[nrof] = i;
			}
			for (int j = 1; j <= i; j++) {//枚举之前的洞是否与这个洞相交，如果相交则合并集合
				
				if (cont(i,j)) {
					int dadd = find(i);
					int dad = find(j);
					if (dadd != dad) {
					    fa[dadd] = dad; }
				}
			}

		}
		bool jud = 0;
		for (int i = 1; i <= nbtm; i++) {
			for (int j = 1; j <= nrof; j++) {
				if (find(btm[i]) == find(rof[j])) {
					jud = 1;
					break;
				}

			}
			if (jud == 1) {
				break;
			}
		}
		if (jud == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}



}