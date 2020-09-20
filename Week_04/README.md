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
https://leetcode-cn.com/problems/word-ladder/

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
1. 基于图的双向广度优先搜索
2. [基于Kotlin实现的第一版](https://leetcode-cn.com/submissions/detail/108079748/)性能比C++的版本好，需进行进一步对比

##### 岛屿数量
https://leetcode-cn.com/problems/number-of-islands/

*实现思路:* 
深度优先搜索、广度优先搜索
岛屿的每块土地都相连，可通过一块土地，访问下一块土地，迭代访问到岛屿的每块土地

*实现难点:*
1. 需要记录每块访问过的土地，避免重复访问，可通过开辟一个新的表格来记录已经访问过的土地格子
2. 比较巧妙的方式是复用输入的二维网格，将访问过的格子标记为`0(水)`，避免额外的空间消耗

*边界场景:*
1. 避免访问到网格之外
2. 提前判断无效的网格，返回0

*使用到的数据结构:*
数组

*进一步优化:*
1. 使用深度优先搜索实现
2. 使用广度优先搜索实现
3. 了解并使用并查集实现

*潜在的坑:*
1. 使用`auto& element = queue.front(); queue.pop_front(); element.first; element.second;`获取并移除队列的第一个元素，再对元素进行访问。可能会因为超过 `queue` 的 capacity ，queue 内部删除了元素，导致访问元素操作出现异常
2. 广度优先搜索的实现涉及元素的创建，可能会带来额外的开销，导致超时


### 本周实战篇

### 本周打卡篇

### 历史回顾篇

## 下一步计划
1. 图的双向广度优先算法
2. 并查集算法
2. 通过题解、提交结果页面参考学习他人的思路和实现