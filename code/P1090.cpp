#include<iostream>
#include<queue>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>>frt;
int sum = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		frt.push(c);
	}
	int a, b;
	while (!frt.empty()) {
		a = frt.top();
		frt.pop();
		b = frt.top();
		frt.pop();
		sum += (a + b);
		if (!frt.empty()) {
			frt.push(a + b);
		}
		else {
			break;
		}


	}
	cout << sum;
}