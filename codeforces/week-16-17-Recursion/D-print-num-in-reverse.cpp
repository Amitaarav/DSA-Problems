#include <bits/stdc++.h>
using namespace std;
 
void reverseNum(long long num){
    if(num == 0){
        return ;
    }
    
    cout << num % 10;
    
    reverseNum(num / 10);
}
int main() {
	long long n;
	cin >> n;
	
	if(n == 0){
	    cout << 0;
	    return 0;
	}
	reverseNum(n);
	return 0;
 
}