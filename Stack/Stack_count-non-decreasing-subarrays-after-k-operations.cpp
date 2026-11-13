//统计最小k次操作后，非递减子数组的数量
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    struct Block{
        long long val;
        long long len;
        long long sum;
    };

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        stack<Block> st;
        long long total_cost = 0;
        long long ans = 0;
        int l = 0;
        int n = nums.size();

        for (int r = 0; r < n; ++r) {
            long long cur_val = nums[r];
            long long cur_sum = 0;
            long long cur_len = 1;

            // 合并栈顶所有 val <= cur_val 的块（被当前更大值覆盖）
            while (!st.empty() && st.top().val <= cur_val) {
                Block b = st.top();
                st.pop();
                // 原来这块的代价是基于旧基准b.val，现在基准变成cur_val
                // 新代价 = (cur_val - b.val) * b.len + b.sum
                cur_sum += (cur_val - b.val) * b.len + b.sum;
                cur_len += b.len;
            }

            st.push({cur_val, cur_len, cur_sum});
            total_cost += cur_sum;

            // 代价超了，移动左边界 l
            while (total_cost > k) {
                Block& top = st.top();
                // 要删掉窗口最左边一个元素
                if (top.len == 1) {
                    total_cost -= top.sum;
                    st.pop();
                } else {
                    // 块长度>1，块内去掉第一个元素
                    total_cost -= top.val - nums[l];
                    top.len--;
                    top.sum -= top.val - nums[l];
                }
                l++;
            }
            // 以 r 为右端点，合法左端点是 [l ... r]，一共 r-l+1 个
            ans += r - l + 1;
        }
        return ans;
    
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 5;
    Solution s;
    cout << s.countNonDecreasingSubarrays(nums, k) << endl;
    return 0;
}