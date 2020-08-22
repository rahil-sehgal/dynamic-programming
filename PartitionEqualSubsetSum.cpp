class Solution {
public:
    //equate their subset sum 
    bool canPartition(vector<int>& nums) {
           int sum=0;
        for(int i=0;i<nums.size()+1;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else return subsetsum(nums,sum/2);
    }
    bool subsetsum(vector<int> a,int sum){
        int n=a.size();
        int t[n+1][sum+1];
            
            
            for(int i=0;i<n+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(i==0 && j!=0){
                        t[i][j]=0;
                    }
                    else if (j==0){t[i][j]=1;}
                     else if(a[i-1]<=j){           //else if(a[i-1]<=sum) ye galat hai
                         t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
                      }
                      else t[i][j]=t[i-1][j];
                }
            }
      
        return t[n][sum];
    }
};
