#include<iostream>
using namespace std;
double a, b, c, d;
double cclt(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

int main() {
	int cnt = 0;

	double x[4];
	cin >> a >> b >> c >> d;
	for (int i = -100; i <= 100; i++) {
		double lf = i;
		double rt = i + 1;
		if (cclt(lf) == 0) {
			if (x[cnt] != lf) {
				printf("%.2lf ", lf);
				cnt++;
				x[cnt] = lf;
				continue;
			}

		}
		if (cclt(rt) == 0) {
			printf("%.2lf ", rt);
			cnt++;
			x[cnt] = rt;
			continue;
		}

		if (cclt(lf) * cclt(rt) < 0) {///===========0
			while (rt - lf >= 0.001) {
				if (cnt == 3) {
					break;
				}
				double md = (lf + rt) / 2;
				if (cclt(md) == 0) {
					printf("%.2lf ", md);
					cnt++;
					x[cnt] = md;
					continue;
				}
				if (cclt(lf) == 0) {
					printf("%.2lf ", lf);
					cnt++;
					x[cnt] = lf;
					continue;
				}
				if (cclt(rt) == 0) {
					printf("%.2lf ", rt);
					cnt++;
					x[cnt] = rt;
					continue;
				}
				if (cclt(md) * cclt(lf) < 0) {
					rt = md;
				}
				else {
					lf = md;
				}

			}
			printf("%.2lf ", rt);
			if (cnt == 3) {
				break;
			}
		}

	}


}