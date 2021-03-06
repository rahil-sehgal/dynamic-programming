#include<iostream>
#include <cstring>
#include<stdio.h>

using namespace std;

//making a t matrix for memoization
int static t[101][1001]; //t[n+1][w+1] as n and w are changing quantities



int knapsack(int wt[], int val[], int W, int n)   //n is the size of array and W is taotal weight of knapsack
{   
     // Base Condition
    if(n==0 || W==0){
        return 0;
    }
    //check if that value is alreday stored int or not
    if(t[n][W]!=-1){
        return t[n][W];
    }
    // recusrive code + memoization
    if(wt[n-1]<=W){
        return t[n][W]= max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1) );
    }
    else return t[n][W]=knapsack(wt,val,W,n-1);
}

int main(){
    memset(t,-1,sizeof(t)); //note: 'memset' is defined in header '<cstring>'; did you forget to '#include <cstring>
    int wt[]={1,3,4,5};
    int val[]= {1,4,5,7};
    int W=7; 
    int n=sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt,val,W,n);
}