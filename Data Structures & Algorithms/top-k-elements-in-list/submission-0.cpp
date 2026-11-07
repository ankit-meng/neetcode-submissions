class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> uMap;
        vector<vector<int>> uFreq(nums.size() + 1);
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            uMap[nums[i]]++;
        }

        for(const auto& [integer, freq]: uMap) {
            uFreq[freq].push_back(integer);
        }

        for(int i = uFreq.size() - 1; i >= 1; i--) {
            
            for(int j = 0; j < uFreq[i].size(); ++j) {
                result.push_back(uFreq[i][j]);

                if (result.size() == k) return result;
            }
        }

        return {};
    }
};
