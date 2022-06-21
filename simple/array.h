#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    /* data */
public:

    int test() {
        return 0;
    }

    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int temp;

        for (int i = 0; i < k; i++) {
            temp = nums[len - 1];
            for (int j = len - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
    }

    // 买卖股票的最佳时机 II
    int maxProfit(vector<int>& prices) {
        int sum = 0;

        // the sum of the prices is the maxinum profit
        for (int i = 1; i < prices.size(); i++) {
            int temp = prices[i] - prices[i - 1];
            if (temp > 0) {
                sum += temp;
            }
        }

        return sum;
    }

    // 删除排序数组中的重复项
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0;
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] != nums[left]) {
                nums[++left] = nums[right];
            }
        }
        
        return ++left;
    }
};
