class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int frequency = 0, count = 0;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& pair : freq) {
            if (pair.second == frequency) {
                count++;
            } else if (pair.second > frequency) {
                frequency = pair.second;
                count = 1;
            }
        }

        return frequency * count;
    
    }
};