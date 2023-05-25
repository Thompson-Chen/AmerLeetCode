# 从零开始的刷题
## 参考
[[力扣刷题攻略] Re：从零开始的力扣刷题生活](https://leetcode.cn/circle/discuss/E3yavq/)


## 章节
### 数组篇
- 对应文件夹： `array`
#### 知识点
- [C++ vector的使用总结及常用vector操作](https://blog.csdn.net/p942005405/article/details/100588611)
- [C++ unordered_map详解](https://blog.csdn.net/zou_albert/article/details/106983268)
- [c++ unordered_map4种遍历方式](https://blog.csdn.net/qq_21539375/article/details/122003559)
#### 做题列表
1. 数组的改变和移动


| 序号 | 题目 | 备注
|----|----|----
| 453| 最小操作次数使数组元素相等| 主要学会该题的“思路转换”
|665|非递减数列|自己最初的做法有点面向测试编程了，应该总结抽象出规则才对
|283|移动零| 双指针法或直接操作下标

2. 旋转数组

| 序号 | 题目 | 备注
|----|----|----
| 189| 轮转数组 | 
|396| 旋转函数| 找规律……暴力法会超时

3. 统计数组中的元素

| 序号 | 题目 | 备注
|----|----|----
| 645 | 错误的集合 | 第一下没做出来
| 697 | 数组的度 | 第一下没做出来。题解使用了hash表，对应的数据结构为unordered_map
| 448 | 找到所有数组中消失的数字 | 三种方法，暴力求解会超时，可以用哈希表来空间换时间，但直接把nums当成hash表进行原地修改，效果更好！
| 442 | 数组中重复的元素 | 和448的方法-即原地修改一样（感觉后面448、442这种题都可以这么来）
| 41 | 缺失的第一个正数 | (困难题) 也是原地hash的思路，但难的是如何设置hash value（前面的题是直接加n，但这道题不是）

4. 数组的遍历

| 序号 | 题目 | 备注
|----|----|----
| 485 | 最大连续1的个数 | (简单题)没什么好讲的
| 495 | 提莫攻击 | （简单题）遍历即可
| 414 | 第三大的数 | （简单题）要求时间复杂度在O(n)，实际上有两种方法，一个是一次遍历，还有一个是利用数据结构（有序集合）set
| 628 | 三个数的最大乘积 | （简单题）可以先排序再找（nlogn）或者直接用线性扫描（n），注意该题要考虑两种情况，不能漏了【两个最小负数 ✖️ 一个最大正数】的可能

5. 二维数组及滚动数组

| 序号 | 题目 | 备注
|----|----|----
| 118 | 杨辉三角 | (简单题)没什么好讲的
| 119 | 杨辉三角 | (简单题)和上一题相比的话主要是看怎么优化——1. 滚动数组；2. 在原数组上进行**逆向** 的操作
| 661 | 图片平滑器 | （简单题）就是二维数组的遍历，注意下细节就好
| 598 | 范围求和II | (简单题) 找最短长和最短宽，根据题来抽象
| 419 | 甲板上的战舰 | 自己做的时候进阶版本的思路是有的，最后也做了出来，但还是太复杂了，可以参考题解（枚举：通过枚举每个战舰的左上顶点（即当前顶点为“X”并且上方和左方为“.“即认为是一艘新的战舰）即可统计战舰的个数。

6. 特定顺序遍历二维数组

| 序号 | 题目 | 备注
|-|-|-
| 54 | 螺旋矩阵 | 每一圈顺时针遍历一圈都是一样的，只不过上下左右边界不同而已，关键是控制好上下左右边界
| 59 | 螺旋矩阵II | 和54思路一样，只不过要注意下二维数组初始化的方式：`vector<vector<int>> res(n, vector<int>(n, 0));`
| 498 | 对角线遍历 | 模拟法，鬼知道我当时做了多久……

7. 二维数组变换

| 序号 | 题目 | 备注
|-|-|-
| 566 | 重塑矩阵 | （简单题）没什么好说的，涉及到/与%操作
| 48 | 旋转图像 | 找规律啊找规律
| 289| 生命游戏 | 要求原地修改，可以设置多个状态，然后第二次遍历的时候再去修改

8. 前缀和数组

| 序号 | 题目 | 备注
|-|-|-
| 303| 区域和检索-数组不可变 | (简单题)
| 304 | 二维区域和检索 - 矩阵不可变| 和上题类似
| 238 | 除自身以外数组的乘积 | 用两个额外的数组存储从左边计算的前缀积和右边计算的前缀积

### 链表篇
- 对应文件夹：`linked_list`

#### 知识点
链表的题通常需要注意两点：
1. 舍得用变量，千万别想着节省变量，否则容易被逻辑绕晕
2. head 有可能需要改动时，先增加一个假head（即哨兵节点sentinel），返回的时候直接取 假head.next，这样就不需要为修改 head 增加一大堆逻辑了。

#### 做题列表

1. 移除与插入链表元素

| 序号 | 题目 | 备注
|-|-|-
| 707 | 设计链表 | 主要学习如何写链表的基本结构
| 203 | 移除链表元素 | 多创建一个哨兵节点（sentinel）指向head，后续直接遍历即可
| 19 | 删除链表的倒数第N个结点 | 使用栈或双指针法可以达成一次遍历的目的
| 82 | 删除排序链表中的重复元素 II | 双指针法

2. 链表的遍历

| 序号 | 题目 | 备注
|-|-|-
| 430 | 扁平化多级双向链表 | 深度优先搜索
| 114 | 二叉树展开为链表 | 