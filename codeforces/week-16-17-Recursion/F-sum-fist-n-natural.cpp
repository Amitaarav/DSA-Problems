#include <bits/stdc++.h>
using namespace std;
 
long long sumNnaturalNumber(long long num){
    // base
    if(num == 1){
        return 1;
    }
    
    return num + sumNnaturalNumber(num - 1);
    
}
int main() {
	int n;
	cin >> n;
	
	long long fact  =  sumNnaturalNumber(n);
	cout << fact;
	return 0;
 
}