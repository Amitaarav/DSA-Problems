class Solution {
public:
    int minMoves(vector<int>& nums) {
        int numberOfMoves = 0;
        int minimumNum = *min_element(nums.begin(), nums.end());

        for(int num : nums){
            numberOfMoves += num - minimumNum;
        }

        return numberOfMoves;
    }
};