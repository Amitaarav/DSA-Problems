#include <bits/stdc++.h>
using namespace std;
 
int  minElement(vector<int> &arr, int n, int mini){
    if(n < 0){
        return mini;
    }
    mini = min(mini, arr[n]);
    return minElement(arr, n - 1, mini);
}
 
int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int mini = INT_MAX;
    
    int res = minElement(arr, n-1, mini);
    cout << res;
 
}