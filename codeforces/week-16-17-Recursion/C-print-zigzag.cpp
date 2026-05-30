#include <bits/stdc++.h>
using namespace std;
 
void printNum (int num){
    // base
    if(num == 0){
        return ;
    }
    
    // recurssive call
    cout << num << endl;
    if(num > 1) printNum(num - 1);
    if(num > 1) cout << num << endl;
}
int main() {
	int n;
	cin >> n;
	
	printNum(n);
	return 0;
 
}