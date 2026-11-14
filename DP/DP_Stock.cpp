//股票问题1
/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

#include<iostream>
#include<vector>

using namespace std;

int Stock(vector<int>& prices){
    int n = prices.size();
    
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = 0;           //今天没有股票时的收益
    dp[0][1] = -prices[0];  //今天手里有股票时的收益

    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], -prices[i]);
    }

    return dp[n-1][0];
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << Stock(prices) << endl;

    return 0;
}