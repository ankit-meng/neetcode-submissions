class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(), 0);
        vector<int> rightProduct(nums.size(), 0);
        vector<int> result(nums.size(), 0);

        leftProduct[0] = nums[0];
        rightProduct[nums.size() - 1] = nums[nums.size() - 1];

        for(int i = 1; i < nums.size(); ++i) {
            leftProduct[i] = nums[i] * leftProduct[i-1];
        }
 
        for(int i = nums.size() - 2; i >= 1; --i) {
            rightProduct[i] = nums[i] * rightProduct[i+1];
        }

        for(int i = 0; i < nums.size(); ++i) {

            if (i-1 < 0) {
                result[i] = rightProduct[i+1];
            } else if (i+1 >= nums.size()) {
                result[i] = leftProduct[i-1];
            } else {
                result[i] = leftProduct[i-1]*rightProduct[i+1];
            }
        } 

        return result;

    }
};
