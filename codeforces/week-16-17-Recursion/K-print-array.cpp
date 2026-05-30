#include <bits/stdc++.h>
using namespace std;
 
void reverseArray(vector<int> &arr, int n){
    if(n < 0){
        return ;
    }
    reverseArray(arr, n - 1);
    cout << arr[n] << " ";
}
 
int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    reverseArray(arr, n-1);
 
}