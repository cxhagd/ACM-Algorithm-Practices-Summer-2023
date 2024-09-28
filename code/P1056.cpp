#include<iostream>
#include<algorithm>
using namespace std;
int M, N, K, L, D;

struct loc {
	int num;
	int cnt;

};
loc x[1011]; loc y[1011];
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
bool cmp(loc a, loc b) {
	return a.cnt > b.cnt;
}
bool cmpp(loc a,loc b){
	return a.num<b.num;
}
int main() {
	cin >> M >> N >> K >> L >> D;
	for (int i = 1; i <= D; i++) {
		int xx, yy, xxx, yyy;
		cin >> xx >> yy >> xxx >> yyy;
		if (xx == xxx) {
			y[min(yy, yyy)].num = min(yy, yyy);
			y[min(yy, yyy)].cnt++;


		}
		if (yy == yyy) {
			x[min(xx, xxx)].num = min(xx, xxx);
			x[min(xx, xxx)].cnt++;
		}
	}
	sort(&x[1], &x[N+ 1], cmp);
	sort(&y[1], &y[M+1], cmp);
    sort(&x[1],&x[K+1],cmpp);
    sort(&y[1],&y[L+1],cmpp);
	for (int i = 1; i <= K; i++) {

		cout << x[i].num << " ";

	}
	cout << endl;

	for (int i = 1; i <= L; i++) {

		cout << y[i].num << " ";

	}


}



