# 学习笔记 Week 4

## 动态规划
1. 分治、回溯、递归，本质上没有多大的差别(关键看有无最优子结构)
	- 共性: 找到重复子问题
	- 差异性: 最优子结构、中途可以淘汰次优解
2. 动态规划有自顶向下(递归)、自底向上(循环)两种解法
3. 划分子问题，画出递归状态树
4. Dynamic Programing
5. 动态规划将一个复杂问题分解为简单子问题，递归求解，采用分治 + 最优子结构
6. 

### 递归代码模板

```python
def recursion(level, praram1, param2, ...):
    # recursion terminator
    if (level > MAX_LEVEL):
        process_result
        return

    # process logic in current level
    process(level, data...)

    # drill down
    self.recursion(level + 1, p1, ...)

    # reverse the current level status if needed
```


### 分治代码模板

```python
def divide_conquer(problem, param1, param2, ...):
    # 1. recursion terminator
    if (problem is Node):
        print_result
        return

    # prepare data
    data = prepare_data(problem)
    subproblems = splt_problem(problem, data)

    # conquer subproblems
    subresult1 = self.divide_conquer(subproblems[0], p1, ...)
    subresult2 = self.divide_conquer(subproblems[1], p1, ...)
    subresult3 = self.divide_conquer(subproblems[2], p1, ...)

    # process and generate the final result
    result = process_result(subresult1, subresult2, subresult3, ...)

    # revert the current level
```