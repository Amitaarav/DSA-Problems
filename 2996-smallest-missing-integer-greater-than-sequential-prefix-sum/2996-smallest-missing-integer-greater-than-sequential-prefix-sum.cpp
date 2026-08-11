class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        // subsequential sums store in map with (sum, size)
        unordered_set<int> st(nums.begin(), nums.end());

        int seqSum = nums[0];
        int r = 1;

        while(r < n){
            if(nums[r] == nums[r - 1] + 1){
                seqSum += nums[r];
                r++;
            } else {
                break;
            }
        }

        while(st.count(seqSum)){
            seqSum++;
        }

        return seqSum;

    }
};