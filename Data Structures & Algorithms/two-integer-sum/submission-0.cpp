class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> remainingValue;

        for(int i = 0; i < nums.size(); ++i) {
            if (remainingValue.contains(target - nums[i])) {
                return {remainingValue[target - nums[i]],i};
            }
            remainingValue[nums[i]] = i;
        }

        return {};
    }
};
