//GCD数组的最小值 
/*
满足所有元素大于0，相邻两个元素最小公倍数大于1的递增数列叫GCD数列 
给定一个数组长度n，一个索引index，一个元素value，要求arr[index] == value 且满足GCD数列的性质 
求出满足条件的数组的最后一个元素
无法满足返回-1 
*/

#include<iostream>
#include<vector>
using namespace std;

long long minimumMaxValue(int n, int index, int value) {
    vector<long long int> arr(n);
    arr[index] = value;

    for(int i = index-1; i >= 0; i--){

        for(int j = 2; j <= arr[i+1]; j++){
            if(arr[i+1] % j == 0){
                arr[i] = arr[i+1] - j;
                break;
            }
            if(arr[i+1] % j == 1){
                return -1;
            }
        }

    }
    long long int step = 0;
    for(int i = 2;;i++){
        if(value % i == 0){
            step = i;
            break;
        }
            
    }

    for(int i = index+1; i < n; i++){
        arr[i] = arr[i-1] + step;
    }

    return arr[n-1];
}
int main(){


    int n = 2;
    int index = 1;
    int value = 3;
    cout << minimumMaxValue(n, index, value) << endl;
    return 0;
}