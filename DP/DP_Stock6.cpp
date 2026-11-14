//股票问题6
/*
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

#include<iostream>
#include<vector>

using namespace std;

int Stock(vector<int>& prices, int k){
    int n = prices.size();
    
    vector<vector<int>> dp(n, vector<int>(2*k+1, 0));

    for(int i = 1; i <= k; i++){
        dp[0][2*i - 1] = -prices[0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= 2*k; j++){
            if(j%2){
                dp[i-1][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
            }
            else{
                dp[i-1][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
            }
        }
    }

    return dp[n-1][2*k];
}

int main(){

    vector<int> prices = {7, 5, 3, 6, 4, 78, 56, 0, 89, 23};
    int k = 5;
    cout << Stock(prices, k) << endl;
    return 0;
}