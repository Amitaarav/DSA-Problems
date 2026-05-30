#include <bits/stdc++.h>
using namespace std;
 
void printNum (int num){
    // base
    if(num == 0){
        return ;
    }
    // recurssive call
    cout << num << endl;
    printNum(num - 1);
}
int main() {
	int n;
	cin >> n;
	
	printNum(n);
	return 0;
 
}