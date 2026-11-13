//给定一个数n，求至少需要多少个完全平方数求和等于n

#include<iostream>
#include<vector>

using namespace std;

int perfectsquares(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    return dp[n];
}

int main(){

    cout << perfectsquares(12);

    return 0;
}