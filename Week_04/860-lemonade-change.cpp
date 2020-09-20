class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 20 面额找零的时候用不上不管
        int tens = 0; // 10 面额
        int fives = 0; // 5 面额

        for (int bill : bills) {
            if (bill == 5) {
                fives++;
            } else 
            if (bill == 10) {
                if (fives) {
                    tens++;
                    fives--;
                } else {
                    return false;
                }
            } else
            if (bill == 20) {
                if (tens && fives) {
                    // 直接找零 15
                    tens--; 
                    fives--;
                } else {
                    if (fives >= 3) {
                        fives -= 3;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// *实现思路:* 
// 贪心算法
// 因为题目中的货币面值满足小额可以整除大额的特性，因此可以尽可能将最大额的钞票找出去，留下小额的用于应对小额找零

// *实现难点:*
// 1. 需要注意，使用大额面值找零后，需要减去已找的钱数
// 2. 由于此题的可能的面额有限，找零的 Case 很少，可以简单对各种可能的输入做分支判断处理

// *进一步优化:*
// 提前比较，而不是计算后再比较，可减少几个指令(理论上有优化，实际效果不大)

