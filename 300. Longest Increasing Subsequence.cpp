class Solution {
public:
    
    //this is an O(n^2) soln through dp
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return n;
        }
        
        
        int dp[n];
        for(int i=0;i<n;++i){
            dp[i]=1;
        }
        //most major step is to inialize dp[n]={1}
        int max1=-1; // cant name it max, name it max1
        
        
        //Base Condn
        
        for(int i=1;i<n;i++){ 
            for(int j=0;j<i;j++){ //j starts from the beginning 
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1); //added 1 in dp[j] to increase the length 
                }
            }
            max1=max(max1,dp[i]);
        }
        
        return max1;
    }
    
    int max(int a,int b){return (a>b)?a:b;}
};
