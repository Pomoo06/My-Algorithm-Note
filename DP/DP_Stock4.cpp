//股票问题4
/*
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
*/

#include<iostream>
#include<vector>

using namespace std;

int Stock(vector<int>& prices, int fee){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2,0));
    dp[0][1] = -prices[0];
    for(int i = 0; i < n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    }

    return dp[n-1][0];
}

int main(){

    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout << Stock(prices, fee) << endl;

    return 0;
}