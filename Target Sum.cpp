class Solution {
public:
    // Divide it into 2 subarrays +ve and -ve part
    //S1 -S2 = diff =S
    int findTargetSumWays(vector<int>& nums, int diff) {
        vector<int> S1;
        //S1+S2=sum
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=vector[i];
        }
        S1=(sum+diff)/2;
        return countOfSubsetsum(nums,S1);
    }
    
    int countOfSubsetsum(vector<int> arr,int sum){
    
        int n=arr.size();
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                 
                if(i==0&&j!=0){
                    t[i][j]=0;
                }
                
                else if(arr[i-1]<=j){
                  t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j]; 
                 }
                else t[i][j]=t[i-1][j];
            }
        }
            return t[n][sum];
        }
        
    
};
