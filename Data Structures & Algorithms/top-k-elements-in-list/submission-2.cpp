class Solution {
   public:
    struct CompareMin {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second < b.second; // Note: '>' creates a min-heap
    }
};

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMin> pq;
        unordered_map<int,int> m;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }

        for(auto const &[key,value]: m) {
            pq.push({key,value});
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
