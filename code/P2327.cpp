#include<iostream>
using namespace std;
int n;
int b[10101];
int a[10101];
int ans = 0;
bool jdg(int i) {

	if (b[i] == a[i - 1] + a[i] + a[i + 1]) {
		return 1;
	}
	else {
		return 0;
	}

}

void now(int k) {


	if (k == 1) {
		a[k] = 1;
	
			now(k + 1);
	    	
		a[k] = 0;
	
			now(k + 1);
		   
    	}
	if (k == n+1) {
		if (jdg(k-1) ) {
			ans++;
			return;
		}
	}
	if (k != 1 &&k!=n+1) {

		a[k] = 1;
		if ( jdg(k - 1)) {
			now(k + 1);
    		}
     	
    	a[k] = 0;
    	if (jdg(k - 1)) {
	    	now(k + 1);
    	}
    }
}
		
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	b[0] = 0;
	b[n + 1] = 0;
	now(1);
	cout << ans;
}