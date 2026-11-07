class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> digits;

        for (int i = 0; i < nums.size(); ++i) {
            if (digits.count(nums[i])) {
                return true;
            }
            digits.insert(nums[i]);
        }
        return false;
    }
};