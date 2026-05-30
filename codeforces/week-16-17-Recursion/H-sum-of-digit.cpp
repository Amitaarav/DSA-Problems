#include <bits/stdc++.h>
using namespace std;
 
long long sumDigit(long long num){
    if(num == 0){
        return 0;
    }
    
    return num % 10 + sumDigit(num / 10);
}
int main() {
	long long n;
	cin >> n;
	
	long long res  =  sumDigit(n);
	cout << res;
	return 0;
 
}