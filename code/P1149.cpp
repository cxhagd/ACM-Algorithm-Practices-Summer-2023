#include<iostream>
using namespace std;
int map[10] = { 6,2,5,5,4,5,6,3,7,6 };
int count(int num)
{
	int summ = 0;
	if (num == 0) {
		return map[0];
	}
	while( num != 0) {
		
        summ += map[num % 10];
		num/= 10;
		
	}
	

	return summ;
}

int main() {
	int n;
	int ans = 0;
		cin >> n;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			

				if (count(i) + count(j) + count(i+j)+4==n) {
					ans++;
				
			}
		}
	}
	cout << ans;
}