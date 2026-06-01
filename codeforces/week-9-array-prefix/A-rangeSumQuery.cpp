#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long long> arr(n + 1);
	
	for(int i = 1; i <= n; i++){
	    cin >> arr[i];
	}
	
    for(int i = 2; i <= n; i++){
        arr[i] += arr[i - 1];
    }
	
	int q;
	cin >> q;
	
	for(int i = 0; i < q; i++){
	    int l,r;
	    cin >> l >> r;
	    
	    if(l == 0) cout << arr[r] << endl;
	    
	    else cout << arr[r] - arr[l - 1] << endl;
	    
	}

}
