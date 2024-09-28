#include<iostream>
#include<algorithm>
using namespace std;
int N;
long long int a[10001];

int ma = 1;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &a[i]);
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		int l = i, r = i;
		while (a[l - 1] <= a[l] && l > 1) {
			l--;
		}
		while (a[r] >= a[r + 1] && r < N) {
			r++;
		}
		
		ma = max(ma, r-l+1);
	}
printf("%d",ma);

}