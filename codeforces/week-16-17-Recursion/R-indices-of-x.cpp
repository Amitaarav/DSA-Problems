#include <bits/stdc++.h>
using namespace std;
 
void allOccurance(vector<long long> &arr, long long index, long long x, vector<long long>& ans){
    
    if(index < 0){
        return;
    }
    
    if(arr[index] == x){
        ans.push_back(index + 1);
    }
    
    allOccurance(arr, index - 1, x, ans);
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
    
    vector<long long> ans;
    
    allOccurance(arr, n, x, ans);
    
    reverse(ans.begin(), ans.end());
    
    if(ans.empty()){
        cout << -1;
    } else {
        for(auto it: ans){
            cout << it << " ";
        }
    }
    
}