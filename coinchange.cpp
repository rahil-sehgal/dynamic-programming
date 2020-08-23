class Solution {
public:
    //we can take a coin any number of times
    // that means it is the case of unbounded knapsack
    //unlimited supply of coins
    //just gotta find those number of subsets dude :))
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        int t[n+1][amount+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0 && j!=0 ){t[i][j]=0;}
                else if(j==0){t[i][j]=1;}
                //else if(coins[i-1]<=amount){         <--------- WRONG ERROR
                else if(coins[i-1]<=j){
                    t[i][j]=min(t[i][j-coins[i-1]], t[i-1][j]); //most imp line // unbounded knapsack
                        
                    
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][amount];
    }
};
