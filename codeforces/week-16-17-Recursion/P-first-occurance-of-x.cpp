#include <bits/stdc++.h>
using namespace std;
 
long long firstOccurance(vector<long long> &arr, int index, long long x){
    if(index == arr.size()){
        return -1;
    }
    
    if(arr[index] == x){
        return index + 1;
    }
    
    return firstOccurance(arr, index + 1, x);
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
    
    long long res = firstOccurance(arr, 0, x);
    cout << res;
}