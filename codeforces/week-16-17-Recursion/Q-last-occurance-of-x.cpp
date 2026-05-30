#include <bits/stdc++.h>
using namespace std;
 
long long lastOccurance(vector<long long> &arr, int index, long long x){
    
    if(index < 0){
        return -1;
    }
    
    if(arr[index] == x){
        return index + 1;
    }
    
    return lastOccurance(arr, index - 1, x);
}
 
int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    long long x;
    cin >> x;
    
    long long res = lastOccurance(arr, n, x);
    cout << res;
}