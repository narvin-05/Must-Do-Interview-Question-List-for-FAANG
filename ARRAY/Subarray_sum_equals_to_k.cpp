// Problem Link - https://leetcode.com/problems/subarray-sum-equals-k/
// Resource - https://www.youtube.com/watch?v=20v8zSo2v18

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int prefix_sum = 0 ;
        mp[prefix_sum] = 1;
        int count_subarray = 0 ;
        
        for(auto it: nums){
            prefix_sum += it;
            int find = prefix_sum-k;
            
            if(mp.find(find) != mp.end())
                count_subarray += mp[find];
            
            mp[prefix_sum]++;
            
        }
        
        return count_subarray;
    }
};