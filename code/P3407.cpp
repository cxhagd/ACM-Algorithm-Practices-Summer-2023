#include<iostream>
#include<algorithm>
using namespace std;
long long int N, T, Q;
long long int ipt[100010];
struct man {
	long long int beg;
	bool sta;
	long long int end;

};
man ps[100010];
int main() {
	cin >> N >> T >> Q;
	int k = 0, m = 0;
	for (int i = 1; i <= N; i++) {
		int status;
		cin >> ps[i].beg >> status;
		if (status == 1) {
			ps[i].sta = 1;//east 
		}
		if (status ==2) {
			ps[i].sta = 0;//west
		}
	}

	for (int i = 1; i <= Q; i++) {
		cin >> ipt[i];
	}

	for (int i = 1; i <= N; i++) {
		if (ps[i].sta == 0) {//west
			if (i == 1) {
				ps[i].end =ps[i].beg- T;
			}
			else {
				if (ps[i - 1].sta == 0) {
					ps[i].end = max(ps[i - 1].end, ps[i].beg - T);
				}
				if (ps[i - 1].sta == 1) {
					ps[i].end = max((ps[i - 1].beg + ps[i].beg) / 2, ps[i].beg-T);
				}
			}
		}
	}

	for (int i = N; i >= 1; i--) {
		if (ps[i].sta == 1) {
			if (i == N) {
				ps[i].end =ps[i].beg+ T;
			}
			else {
				if (ps[i + 1].sta == 1) {
					ps[i].end = min(ps[i + 1].end, ps[i].beg + T);
				}
				if (ps[i + 1].sta == 0) {
					ps[i].end = min( (ps[i + 1].beg+ps[i].beg)/2, ps[i].beg + T);
				}


			}
		}
	}





	for (int i = 1; i <=Q; i++) {
		cout << ps[ipt[i]].end << endl;
	}




}