#include <bits/stdc++.h>
using namespace std;
 
void reverseArray(vector<int> &arr, int n){
    if(n < 0){
        return ;
    }
    cout << arr[n] << " ";
    reverseArray(arr, n - 1);
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