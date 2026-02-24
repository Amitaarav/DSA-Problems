#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int nums[], int n, int x){
    for(int i = 0; i < n; i++){
        if( nums[i] == x){
            return true;
        }
    }
    return false;
}
int main() {
	int n;
	cin >> n;
	
	int nums[n];
	
	for(int i = 0; i < n; i++){
	    cin >> nums[i];
	}
	
    int x;
    cin >> x;
    
	
    linearSearch(nums, n, x) ? cout << "YES" : cout << "NO";
    
	return 0;
}