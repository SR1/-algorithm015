# 学习笔记 Week 4

## 深度优先搜索、广度优先搜索的实现和特性

1. 区别于暴力搜索
2. 在树/图/状态集中寻找特定节点
3. 状态集的场景：棋盘的变化、数独的变化
4. 对图进行搜索需要添加 visited 标记已访问过的节点
5. 搜索是对节点进行访问，且只会访问一次
6. 根据访问顺序的差别，分为：深度优先搜索、广度优先搜索、带优先级的搜索(启发式搜索)
7. 深度优先搜索的实现两种: 使用递归的实现、使用手动维护栈 + 循环的方式实现
8. 广度优先搜索的实现一般使用队列 + 循环

## 贪心算法的实现和特性

1. 贪心算法的每一步选择都采取当下状态下最好/最优的选择，希望以此得到全局最好/最优的算法
2. 区别于动态规划:
	- 贪心对每个问题的子问题的解决方案作出选择
	- 贪心算法不能回退
	- 动态规划可以理解为是带最优方案的回溯算法
3. 适用的问题:
	- 最小生成树
	- 哈夫曼编码
	- 希望通过相对高效来取得结果比较接近最优解答案的场景
4. 适用场景的问题特征:
	- 问题可分解成子问题
	- 子问题的最优解可递推到最终问题的最优解(最优子结构)

## 二分查找的实现和特性

1. 二分查找的适用条件:
	- 数据的目标函数具有单调性
	- 存在上下界
	- 可以通过索引访问到数据
2. 代码模板:
	- C++
		```cpp
		int binarySearch(const vector<int>& nums, int target) {
			int left = 0, right = (int) nums.size() - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] == target) return mid;
				if (nums[mid] < target) left = mid + 1;
				else right = mid - 1;
			}
			return -1;
		}
		```
	- Java
		```java
		public int binarySearch(int[] array, int target) {
			int left = 0, right = array.length - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (array[mid] == target) return mid;
				if (array[mid] < target) left = mid + 1;
				else right = mid - 1;
			}
			return -1;
		}
		```

## 解题回顾

### 本周作业篇

#### 深度/广度优先搜索

##### 单词接龙
https://leetcode-cn.com/problems/word-ladder/description/

*实现思路:* 
广度优先搜索

*实现难点:*
1. 构建单词的转换关系，即从 word => nextWords 的关系图
2. 当字典很大的情况下，容易超时
	- 单词转换算法的调优(基于字典转换 or 基于每个字符替换查找)
	- 按需生成单词转换表
	- set 和 unordered_set 的区别

*边界场景:*
1. wordList 不包含 endWord 时，提前终止
2. 引入 visited 避免重复选中已访问过的单词

*使用到的数据结构:*
deque: 双端队列
1. push_back 往对尾添加元素
2. empty 队列是否为空
3. size 获取队列的大小
4. front 访问队列的第一个元素
5. pop_front 移除队列的第一个元素

set: 基于红黑树的集合，内部有序
unordered_set: 基于哈希的集合，内部无需
1. insert 插入元素
2. size 获取集合大小
3. find 查找元素是否在集合中，当返回值 == set.end() 时，表示没找到

*进一步优化:*
基于图的双向广度优先搜索


### 本周实战篇

### 本周打卡篇

### 历史回顾篇