class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum 0 occurs once before starting
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            prefixSum += num;

            // If there is a previous prefix sum such that
            // prefixSum - previousPrefix = k
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            // Store/update current prefix sum
            mp[prefixSum]++;
        }

        return count;
    }
};