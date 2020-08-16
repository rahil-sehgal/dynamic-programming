class Solution {
public:
    bool subsetsum(vector<int> arr,int sum){
       int n=arr.size();
        int t[n+1][sum+1];
      
        //base condition
        for(int i=0;i<n;i++){
            for(int j=0;j<sum;j++)
            {
                if(i==0&&j!=0) t[i][j]=0;
                else if(j==0) t[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
             if(arr[i-1]<sum){
            t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
        else       t[i][j]= t[i-1][j];
            
                }
        }
    return t[n-1][sum-1];
        
    }
    
    
    bool canPartition(vector<int>& nums) {
       int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n=nums.size();
        
        if(sum%2!=0){
            return false;
            }
        else {
            return subsetsum(nums,sum/2);
        }
    }
};
