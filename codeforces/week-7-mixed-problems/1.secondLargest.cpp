#include<bits/stdc++.h>
using namespace std;
int secondLargestElement(int arr[], int n){
    int largest = arr[0];
    int secondLargest = INT_MIN;
    if(n < 2) return -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > largest ){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN) return -1;
    return secondLargest;
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << secondLargestElement(arr, n);
}