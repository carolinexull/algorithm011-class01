class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return result;
    }
    void backtrack(vector<int> nums, vector<int>& track) {
        if(track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        int size = nums.size();
        for(int i = 0; i < size; ++ i) {
            if(find(track.begin(), track.end(), nums[i]) == track.end()) {
                track.push_back(nums[i]);
                backtrack(nums, track);
                track.pop_back();
            }
        }
    }
};