#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int res = 0;
        sort(nums.begin(), nums.end()); // sorted the array

        vector<int> power(n,1);
        for(int i = 1; i < n; i++){
            power[i] = (power[i-1] * 2) % mod;
        }
        int left  = 0;
        int right = n-1;

        while(left <= right){
            if(nums[left] + nums[right] <= target){
                res += power[right - left] % mod;
                left++;
            }else{
                right--;
            }
            
        }

        return res;
    }
};

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    Solution s;
    int res = s.numSubseq(nums, t);
    cout << res;
}