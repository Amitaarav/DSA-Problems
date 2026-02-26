#include<bits/stdc++.h>
using namespace std;

void pushZeroEnd(long long arr[], int n){
    int nextZeroIndex = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[nextZeroIndex]);
            nextZeroIndex++;
        }
        
    }
    
}

int main(){
    int t;
    cin >> t;

    
    while(t--){
        int n;
        cin >> n;
        
        long long arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        pushZeroEnd(arr, n);
        
        for(int i = 0; i < n; i++){
            cout <<  arr[i] << " ";
        }
        cout << endl;
    }
    
}