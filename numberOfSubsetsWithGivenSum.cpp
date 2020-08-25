 int countsubsetsum(vector<int> arr,int sum){
        //subset sum similar to 0/1 knapsack
        int n=arr.size();
        int t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
                }
                else   t[i][j]= t[i-1][j];
            }
        }
        return t[n][sum];
    }
