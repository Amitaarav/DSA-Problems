#include <bits/stdc++.h>
using namespace std;
 
void printNums(vector<int>& nums, int low, int high){
    
    for(int i = low; i <= high; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}
 
void merge(vector<int>& nums, int low, int mid, int high){
 
    vector<int> temp;
    
    int left = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high){
 
        if(nums[left] > nums[right]){
            temp.push_back(nums[right]);
            right++;
        }else{
            temp.push_back(nums[left]);
            left++;
        }
    }
    
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
    
    cout << "Merge: " << "[" << low << " " << high << "]" << " -> ";
    
    printNums(nums, low, high);
 
}
 
void mergeSort(vector<int>& nums, int low, int high){
    
    if(low >= high){
        return ;
    }
    
    cout << "Divide: [" << low << " " << high << "]" << endl;
    
    int mid = (low + high)/2;
    
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    
    merge(nums, low, mid, high);
}
 
int main() {
	int n;
	cin >> n;
	
	vector<int> nums(n);
	
	for(int i = 0; i < n; i++){
	    cin >> nums[i];
	}
 
 
	mergeSort(nums, 0, n - 1);
	
    return 0;
    
}