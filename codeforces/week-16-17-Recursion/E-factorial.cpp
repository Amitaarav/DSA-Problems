#include <bits/stdc++.h>
using namespace std;
 
long long factorial(long long num){
    // base
    if(num == 0 || num == 1){
        return 1;
    }
    
    return num * factorial(num - 1);
    
}
int main() {
	int n;
	cin >> n;
	
	long long fact  =  factorial(n);
	cout << fact;
	return 0;
 
}