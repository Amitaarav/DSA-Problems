#include <bits/stdc++.h>
using namespace std;
 
vector<int> sorted(vector<int>& nums1, vector<int>& nums2, vector<int>& nums){
 
    int it1 = 0;
    int it2 = 0;
    
    while(it1 < nums1.size() && it2 < nums2.size()){
        if(nums1[it1] > nums2[it2]){
            nums.push_back(nums2[it2]);
            it2++;
        }else{
            nums.push_back(nums1[it1]);
            it1++;
        }
    }
    
    while(it1 < nums1.size()){
        nums.push_back(nums1[it1]);
        it1++;
    }
    
    while(it2 < nums2.size()){
        nums.push_back(nums2[it2]);
        it2++;
    }
    
    return nums;
}
 
int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> nums1(n);
	for(int i = 0; i < n; i++){
	    cin >> nums1[i];
	}
	
	vector<int>nums2(m);
	for(int i = 0; i < m; i++){
	    cin >> nums2[i];
	}
	vector<int> nums;
	
	sorted(nums1, nums2, nums);
	
 
	for(int it : nums){
	    cout << it << " ";
	}
    
    return 0;
    
}