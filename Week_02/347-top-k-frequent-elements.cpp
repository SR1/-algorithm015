class Solution {
public:
    static bool compare(pair<int, int>& first, pair<int, int>& second) {
        return first.second > second.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>,  vector<pair<int, int>>, decltype(&compare)> heap(compare);
        for (auto& [num, count] : freq) {
            if (heap.size() == k) {
                if (heap.top().second < count) {
                    heap.pop();
                    heap.emplace(num, count);
                }
            } else {
                heap.emplace(num, count);
            }
        }

        vector<int> result;
        while(!heap.empty()) {
            result.push_back(heap.top().first);
            heap.pop();
        }
        return result;
    }
};
