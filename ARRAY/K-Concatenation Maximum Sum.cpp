class Solution {
private:
    int kadane(vector<int>& arr){
        long long M = 1000000007;
        int curr_sum = arr[0];
        int best_sum = arr[0];
        for(int i = 1 ; i < arr.size() ; i++){
            if(curr_sum >= 0)
                curr_sum += arr[i];
            else
                curr_sum = arr[i];
            
            if(curr_sum > best_sum)
                best_sum = curr_sum;
            
            curr_sum %= M;
            best_sum %= M;
        }
        if(best_sum < 0)
            return 0 ;
        return best_sum;
    }
    
    int kadaneofTwo(vector<int>& arr,int n){
        vector<int> newArr(2*n);
        for(int i = 0 ; i < n ; i++)
            newArr[i] = arr[i] ;  
            
        for(int i = 0 ; i < n ; i++)
            newArr[i+n] = arr[i] ; 
             
        return kadane(newArr);
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long M = 1000000007;
        long long sum = (accumulate(arr.begin(),arr.end(), 0))%M;
        
        if(k == 1){
            return kadane(arr);
        }
        else if( sum < 0){
            return kadaneofTwo(arr,n);
        }
        else{
            return kadaneofTwo(arr,n)+ ((((k-2)*sum)%M))%M;
        }
    }
};