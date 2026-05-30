#include <bits/stdc++.h>
using namespace std;
 
int fibonacci(int num){
    // base
    if(num == 1){
        return 0;
    }
    
    if(num == 2){
        return 1;
    }
    
    return fibonacci(num - 1) + fibonacci(num - 2);
    
}
int main() {
	int n;
	cin >> n;
	
	int fib  =  fibonacci(n);
	cout << fib;
	return 0;
 
}
