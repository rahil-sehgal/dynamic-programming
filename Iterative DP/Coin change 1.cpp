//CORRECT ANS
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
                
                
                if(i==0 && j!=0 ){t[i][j]=INT_MAX-1;}
                else if(j==0){t[i][j]=0;}
                
                //else if(coins[i-1]<=amount){         <--------- WRONG ERROR
                else if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j]); //most imp line // unbounded knapsack
                        
                    
                }
                else t[i][j]=t[i-1][j];
            }
        }
        if(t[n][amount]==INT_MAX-1){return -1;}
        else return t[n][amount];
    }
};



<-------------Do not initialize the second row

//WRONG ANS
//150 / 182 test cases passed.

//[186,419,83,408]
//6249
//above test case not passed 


class Solution {
public:
    //we can take a coin any number of times
    // that means it is the case of unbounded knapsack
    //unlimited supply of coins
    //just gotta find those number of subsets dude :))
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int t[n+1][amount+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                
                
                if(i==0 && j!=0 ){t[i][j]=INT_MAX-1;}
                else if(j==0){t[i][j]=0;}
                else if(i==1&&j!=0){
                  //if(amount%coins[i-1]==0){     <----------WRONG 
                  if(amount%coins[i-1]==0){
                        t[i][j]=j/coins[i-1];
                    }
                    else t[i][j]=INT_MAX-1;
                }
                //else if(coins[i-1]<=amount){         <--------- WRONG ERROR
                else if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j]); //most imp line // unbounded knapsack
                        
                    
                }
                else t[i][j]=t[i-1][j];
            }
        }
        if(t[n][amount]==INT_MAX-1){return -1;}
        else return t[n][amount];
    }
};
