class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowsize = matrix.size();
        if (rowsize == 0) return false;
        int columnsize = matrix[0].size();

        int allsize = rowsize * columnsize;
        
        int left = 0;
        int right = allsize - 1;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            
            int row = middle / columnsize;
            int col = middle % columnsize;
            int middleValue = matrix[row][col];
            if (middleValue == target) {
                return true;
            }

            if (middleValue < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }
};

// **实现思路:**

// 二分查找
// 容易想到的是分别对行、列做二分查找，先二分查找到目标行，再在目标行里二分查找到目标
// 由于题目是 m x n 的矩阵，有一种简化实现的方式是将搜索区间简化成一维 [0, m x n) 区间

// **实现难点:**

// 1. 如果是分别对行、列二分查找，需要注意避免二分查找的相关变量相互混淆

// **边界场景:**

// 1. 如果是一个空矩阵，或者是一个只有空行的矩阵，需要提前终止
