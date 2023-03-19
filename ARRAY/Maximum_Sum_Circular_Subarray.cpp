// Probelm Link - https://leetcode.com/problems/maximum-sum-circular-subarray/
// Resource - https://www.youtube.com/watch?v=InIRW8E7ofc




class Solution {
private:
    
    int kadanes(vector<int>& nums){
        int curr_sum = nums[0] , max_so_far = nums[0];
        int n = nums.size();
        
        for(int i = 1 ; i < n ; i++){
            if(curr_sum > 0)
                curr_sum += nums[i];
            else
                curr_sum = nums[i];
            
            if(curr_sum > max_so_far)
                max_so_far = curr_sum;
            
        }
        return max_so_far;
    }
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxSubarraySum = kadanes(nums);
        
        int count_positive = 0 ;
        
        int inverted_array_sum = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] *= -1;
            if(nums[i]>0)   count_positive++;
            inverted_array_sum += nums[i];
        }
        
        if(count_positive == nums.size()){
            return maxSubarraySum;
        }
        
        int maxSubarraySum_Reverse = kadanes(nums);
        
        int inverted_ans = (-1)*(inverted_array_sum - maxSubarraySum_Reverse); 
        
        return max(inverted_ans,maxSubarraySum);
        
    }
};