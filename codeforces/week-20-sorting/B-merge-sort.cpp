#include <bits/stdc++.h>
using namespace std;
 
vector<int> merge(vector<int>& leftNums, vector<int>& rightNums){
 
    vector<int> nums;
    
    int it1 = 0;
    int it2 = 0;
    
    while(it1 < leftNums.size() && it2 < rightNums.size()){
        if(leftNums[it1] > rightNums[it2]){
            nums.push_back(rightNums[it2]);
            it2++;
        }else{
            nums.push_back(leftNums[it1]);
            it1++;
        }
    }
    
    while(it1 < leftNums.size()){
        nums.push_back(leftNums[it1]);
        it1++;
    }
    
    while(it2 < rightNums.size()){
        nums.push_back(rightNums[it2]);
        it2++;
    }
    
    return nums;
}
 
vector<int> mergeSort(vector<int> nums){
    if(nums.size() <= 1){
        return nums;
    }
    
    int mid = nums.size() / 2;
    
    vector<int> leftNums(nums.begin(), nums.begin() + mid);
    vector<int> rightNums(nums.begin() + mid, nums.end());
    
    leftNums = mergeSort(leftNums);
    rightNums = mergeSort(rightNums);
    
    return merge(leftNums, rightNums);
}
 
int main() {
	int n;
	cin >> n;
	
	vector<int> nums(n);
	
	for(int i = 0; i < n; i++){
	    cin >> nums[i];
	}
 
 
	nums = mergeSort(nums);
	
    for(int it : nums){
        cout << it << " ";
    }
    return 0;
    
}