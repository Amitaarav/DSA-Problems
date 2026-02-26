#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r, int pivot){
    while(l <= r){
        while(arr[l] < pivot){
            l++;
        }
        while(arr[r] > pivot){
            r--;
        }
        if(l <= r){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quickSort(int arr[], int l, int r){
    if(l >= r){
        return ;
    }
    int pivot = arr[l+ (r-l)/2];
    int partitionIndex = partition(arr, l, r, pivot);
    quickSort(arr, 0, partitionIndex - 1);
    quickSort(arr, partitionIndex, r);
}

int main(){
    int arr[5] = {50,23,9,10,2};
    cout<<"Previously:"<<endl;
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,4);
    cout<<"After Sorting"<<endl;
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}