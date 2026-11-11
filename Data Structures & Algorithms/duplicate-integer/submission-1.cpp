class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> uMap;

        for(auto num: nums) {
            uMap[num]++;
            if (uMap[num] > 1) return true;
        }

        return false;
    }
};