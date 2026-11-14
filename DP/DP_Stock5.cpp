//股票问题5
/*
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

不能连续购买 联想打家劫舍
*/

#include<iostream>
#include<vector>

using namespace std;

int Stock(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(0, prices[1] - prices[0]);
    dp[1][1] = -min(prices[0], prices[1]);

    for(int i = 2; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
    }

    return dp[n-1][0];
}

int main(){

    vector<int> prices = {1,2,3,0,2};
    cout << Stock(prices) << endl;

    return 0;
}