#include<iostream>
#include<algorithm>
using namespace std;
int v[5];
char syb[5] = { '0','+','-','*','/' };
int cclt(int a, int sign, int b) {
	if (sign == 1) {
		return a + b;
	}
	if (sign == 2) {//为什么？ 
		return max(a - b, b - a);
	}
	if (sign == 3) {
		return a * b;
	}
	if (sign == 4) {
		if (b == 0||a==0) {
			return -99999;
		}
		if (a >= b && a % b == 0) {
			return (a / b);
		}
		else {
			if (b > a && b % a == 0) {
				return (b / a);
			}
			else {
				return-999999;
			}

		}
	}
	return 0;
}


void print(bool cho, int i, int j, int k) {
	if (cho == 1) {
		int tp1, tp2, tp3;
		tp1 = cclt(v[1], i, v[2]);
		tp2 = cclt(tp1, j, v[3]);
		tp3 = cclt(tp2, k, v[4]);
		cout << max(v[1], v[2]) << syb[i] << min(v[1], v[2]) << "=" << tp1 << endl;
		cout << max(tp1, v[3]) << syb[j] << min(tp1, v[3]) << "=" << tp2 << endl;
		cout << max(tp2, v[4]) << syb[k] << min(tp2,v[4]) << "=" << tp3 << endl;
	}
	if (cho == 0) {
		int tp1, tp2, tp3;
		tp1 = cclt(v[1], i, v[2]);
		tp2 = cclt(v[3], k, v[4]);
		tp3 = cclt(tp1, j, tp2);
		cout << max(v[1], v[2]) << syb[i] << min(v[1], v[2]) << "=" << tp1 << endl;
		cout << max(v[3], v[4]) << syb[k] << min(v[3], v[4]) << "=" << tp2 << endl;
		cout << max(tp1, tp2) << syb[j] << min(tp1, tp2) << "=" << tp3<< endl;

	}

}

int main() {
	cin >> v[1] >> v[2] >> v[3] >> v[4];
	sort(&v[1], &v[5]);

	do {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				for (int k = 1; k <= 4; k++) {
					if (cclt(cclt(cclt(v[1], i, v[2]), j, v[3]), k, v[4]) == 24) {
						print(1, i, j, k);
						return 0;
					}
					else {
						if (cclt(cclt(v[1], i, v[2]), j, cclt(v[3], k, v[4])) == 24) {
							print(0, i, j, k);
							return 0;
						}
						
					}
				}
			}
		}
	} while (next_permutation(&v[1], &v[5]));
	cout << "No answer!" << endl;

}