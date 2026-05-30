#include <bits/stdc++.h>
using namespace std;
 
long long power(int num, int x){
    // base
        if(x == 0){
        return 1;
    }
    
    
    if(num == 0){
        return 0;
    }
    
    return num * power(num, x - 1);
    
}
int main() {
	int n, x;
	cin >> n >> x;
	
	long long res  =  power(n, x);
	cout << res;
	return 0;
 
}