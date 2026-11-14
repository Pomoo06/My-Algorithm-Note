//股票问题3
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

#include<iostream>
#include<vector>

using namespace std;

int Stock(vector<int>& prices){
    
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    /*
    1表示第一次买入
    2表示第一次卖出
    3表示第二次买入
    4表示第二次卖出
    */
    for(int i = 1; i < n; i++){
        //今天是第一次交易手里没有股票的情况 手里的收益应该是昨天手里没有股票的收益 和今天卖出去昨天的股票的最大值
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        //今天是第一次交易手里有股票的情况 手里的收益应该是昨天手里有股票的收益 和今天买入的最大值
        dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
        //今天是第二次交易手里没有股票的情况 手里的收益应该是昨天手里没有股票的收益 和今天卖出昨天的股票的最大值
        dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
        //今天是第二次交易手里有股票的情况 手里的收益应该是昨天手里有股票的收益 和今天买入的最大值
        dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);

    }

return dp[n-1][4];
    

}

int main(){

    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << Stock(prices) << endl;

    return 0;
}