#include<iostream>
using namespace std;


int main() {
	int x, y;
	int sum = 0;
	cin >> x >> y;
	for (int i = x; i <= y; i++) {
		int t = i;
		int ge;
		while (t != 0) {
			ge = 0;
			ge = t - (int)(t /10)*10;
			t = t / 10;
			if (ge == 2) {
				sum++;
			}
		}
	}
	cout << sum;
}