class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> _map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        vector<int> res;
        int i;

        for (i = 0; i < nums.size(); i++) {
            _map[nums[i]]++;
        }
        auto iter = _map.begin();
        while (iter!= _map.end()) {  
            q.push(*iter); 
            ++iter;  
        } 

        for ( i = 0; i < k; i++) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};