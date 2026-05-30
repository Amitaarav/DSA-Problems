#include <bits/stdc++.h>
using namespace std;
 
long long  sumElement(vector<int> &arr, int n, long long sum){
    if(n < 0){
        return sum;
    }
    
    sum += arr[n];
    return sumElement(arr, n - 1, sum);
}
 
int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    long long sum = 0;
    
    long long res = sumElement(arr, n-1, sum);
    cout << res;
 
}