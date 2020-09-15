class Solution {
public:
    int combinationSum4(vector<int>& nums, int sum) {
        int n=nums.size();
        if(n==0){return 0;}
        if(sum==0){return 1;}
        int t[n+1][sum+1];
        
        //no of ways
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0&&j!=0){t[i][j]=0;}
                else if(j==0){t[i][j]=1;} //empty subset
                else if(nums[i-1]<=j){
                    t[i][j]=t[i][j-nums[i-1]] + t[i-1][j];
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
};

//order also matters 
