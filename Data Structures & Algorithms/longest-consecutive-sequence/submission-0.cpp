class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uSet;
        int longest = 0;

        for (int i = 0; i < nums.size(); ++i) {
            uSet.insert(nums[i]);
        }

        for(int number: uSet) {
            
            if(uSet.count(number - 1) == 0) {

                int length = 1;
                int currNum = number;

                while (uSet.count(currNum+1) == 1) {
                    length++;
                    currNum++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
