#include <bits/stdc++.h>
using namespace std;

bool binarySearch(long long nums[], int n, long long x){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] == x){
            return true;
        }
        else if( nums[mid] > x){
            end = mid - 1;
        }else {
            start = mid + 1;
        } 
    }
    return false;
}

// void sort(long long nums[], int n){
//     for(int i = 1; i < n; i++){
//         long long num = nums[i];
//         int j = i - 1;
//         while(j >= 0 && nums[j] > num){
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         nums[j + 1] = num;
//     }
// }

int main() {
	int n;
	cin >> n;
	
	long long nums[n];
	
	for(int i = 0; i < n; i++){
	    cin >> nums[i];
	}
	
    long long x;
    cin >> x;
    // sort(nums, n);
    
    
    binarySearch(nums, n, x) ? cout << "YES" : cout << "NO";
    
	return 0;
}