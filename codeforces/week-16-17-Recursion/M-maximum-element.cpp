#include <bits/stdc++.h>
using namespace std;
 
int  maxElement(vector<int> &arr, int n, int maxi){
    if(n < 0){
        return maxi;
    }
    maxi = max(maxi, arr[n]);
    return maxElement(arr, n - 1, maxi);
}
 
int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int maxi = INT_MIN;
    
    int res = maxElement(arr, n-1, maxi);
    cout << res;
 
}