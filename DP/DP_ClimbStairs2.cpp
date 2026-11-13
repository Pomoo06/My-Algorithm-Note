//爬楼梯2
/*
你正在爬一个有 n + 1 级台阶的楼梯，台阶编号从 0 到 n。
你还得到了一个长度为 n 的 下标从 1 开始 的整数数组 costs，其中 costs[i] 是第 i 级台阶的成本。
从第 i 级台阶，你 只能 跳到第 i + 1、i + 2 或 i + 3 级台阶。从第 i 级台阶跳到第 j 级台阶的成本定义为： costs[j] + (j - i)2
你从第 0 级台阶开始，初始 cost = 0。
返回到达第 n 级台阶所需的 最小 总成本。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minCostClimbingStairs(vector<int> costs, int n){
    if(n == 1) return costs[1] + 1;
    if(n == 2) return min(costs[1] + costs[2] + 2, costs[2] + 4);

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = costs[1] + 1;
    dp[2] = min(dp[1] + costs[2] + 1, costs[2] + 4);

    for(int i = 3; i <= n; i++){
        dp[i] = min({dp[i-3] + 9, dp[i-2] + 4, dp[i-1] + 1}) + costs[i];
    }

    return dp[n];
}

int main(){
    int n = 4;
    vector<int> costs = {0,1, 2, 3, 4};
    cout << minCostClimbingStairs(costs, n) << endl;
    return 0;
}