class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int> mp;
        int n = nums.size();

        for(int x : nums) {

            mp[x]++;

            if(mp[x] > n/2)
                return x;
        }

        return -1;
    }
};
/*class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j])
                    count++;
            }

            if(count > n/2)
                return nums[i];
        }

        return -1;
    }
};*/