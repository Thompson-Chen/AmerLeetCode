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
- 链表的题通常需要注意两点：
1. 舍得用变量，千万别想着节省变量，否则容易被逻辑绕晕
2. head 有可能需要改动时，先增加一个假head（即哨兵节点sentinel），返回的时候直接取 假head.next，这样就不需要为修改 head 增加一大堆逻辑了。

- [C++ STL栈（stack）结构及使用](https://blog.csdn.net/Flag_ing/article/details/123554966)
- 在【链表的旋转和反转】时，一定！一定！一定要在草稿纸上画一下，否则很容易在指针变换时成环从而报错！
- [Leetcode博客：一文搞定链表常见问题](https://leetcode.cn/problems/linked-list-cycle/solutions/175734/yi-wen-gao-ding-chang-jian-de-lian-biao-wen-ti-h-2/)

#### 做题列表

1. 移除与插入链表元素

| 序号 | 题目 | 备注
|-|-|-
| 707 | 设计链表 | 主要学习如何写链表的基本结构
| 203 | 移除链表元素 | 多创建一个哨兵节点（sentinel）指向head，后续直接遍历即可
| 19 | 删除链表的倒数第N个结点 | 使用栈或双指针法可以达成一次遍历的目的
| 83 | 删除排序链表中重复的元素 | （ 简单题）
| 82 | 删除排序链表中的重复元素 II | 双指针法

2. 链表的遍历

| 序号 | 题目 | 备注
|-|-|-
| 430 | 扁平化多级双向链表 | 深度优先搜索
| 114 | 二叉树展开为链表 | 前序遍历

3. 链表的旋转与反转

| 序号 | 题目 | 备注
|-|-|-
| 61 | 旋转链表 | 两次遍历,第一次遍历到尾节点，第二次遍历到新的头节点
| 24 | 两两交换链表中的节点 | 1. 模拟法，三指针进行交换；2. 递归
| 206 | 反转链表 | 谨记：无论用栈还是用递归，在修改时都要小心链表成环！！；其次在使用`递归`时，一个方便思考的方法是先想清楚这个递归函数是干什么的，其返回值是什么，通过假设其余部分已经完成了工作，辅助思考前面的部分要如何完成，从而界定边界条件（对于本题来说，其关键在于反向工作。假设链表的其余部分已经被反转，现在应该如何反转它前面的部分——即假设从节点nk+1到nm（nm为tail节点）已经被反转，而我们正处于nk）
| 92 | 反转链表 II | 这道题耗了很多时间，主要是在画图的时候没有仔细可能存在的“成环问题”
​| 25 | K个一组翻转链表 | （困难题）模拟法，感觉和前面的题目差不多，当不起“困难”的难度


4. 链表高精度加法

| 序号 | 题目 | 备注
|-|-|-
|2| 两数相加 | 1. 模拟法（情况要覆盖全，关键是不要漏），最终要的是，不要忘记最后判断carry是否还是1的情况！！
|445| 两数相加 II | 其实是在“两数相加”的基础上将排列顺序调换了一下，而且其实不用一定要在最长的链表上进行修改操作，直接遇到空节点进行补新节点就好了
|0205 |面试题 02.05. 链表求和 | 和第二题基本一样。要考虑*正向*或*反向*存储，同时要考虑最后carry是否为1

5. 链表的合并

| 序号 | 题目 | 备注
|-|-|-
|21| 合并两个有序链表 | (简单题)没什么好说的，可以参考下递归是怎么做的
|***23***| 合并K个有序列表 | （分治法）感觉是归并排序，但是就是没做出来

6. 链表中的双指针技巧

| 序号 | 题目 | 备注
|-|-|-
| 86 | 分隔链表 | 自己做的时候时间上用了三指针，一个指向当前小于x的子链表的末尾，一个指向当前要判断的节点，一个指向了当前要判断的节点的前驱节点
| 19 | 删除链表的倒数第N个结点 | 使用栈或双指针法可以达成一次遍历的目的
| 141| 环形链表 | （简单题）典中典了属于是。快慢双指针，类似于径赛中400环形跑道的“套圈”
| 142| 环形链表II | 推数学公式，得到“相遇点到成环点的距离和起点到成环点的距离相等”的结论
| 876 | 链表的中间节点|（简单题）快慢双指针
| 143 | 重排链表 | 1. STL的deque双端队列好像Leetcode总是会报错；2. 链表反转+链表中点+链表合并(**这道题要好好看看**)
| 160 | 相交链表 | （简单题）用栈来反向匹配、哈希表数据结构也类似；双指针解法也有点意思可以看看。[本题题解](https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/811625/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/)


### 链表篇
#### 知识点

1. [C++ STL unordered_map容器用法详解](http://c.biancheng.net/view/7231.html)
2. [C++ STL unordered_set容器完全攻略](http://c.biancheng.net/view/7250.html)


#### 做题列表

1. 哈希表的查找、插入及删除

| 序号 | 题目 | 备注
|-|-|-
| 706 | 设计哈希映射 |  (简单题)了解hash表的存储原理
| 217 | 存在重复元素| (简单题)
| 349 | 两个数组的交集 | (简单题)方法1：哈希集合；方法2：排序+双指针
| 290 | 单词规律 | (简单题) 但是涉及到“双射”的知识
| 128 | 最长连续子序列 | 暴力法：先sort，然后遍历；若要求O(n)的时间复杂度：可以使用unordered_set解决，同时添加一个跳过条件从而避免n平方的遍历总开销（具体见代码）
| 532 | 数组中的 k-diff 数对 | unordered_set的应用，题目比较简单，但要注意对重复值的过滤
| 205 | 同构字符串 | （简单题）unordered_map的应用。虽然简单但是也卡了一会儿，“双射”的应用
| 138 | 复制带随机指针的链表 | 本题的难点其实是在随机指针这里，但其实用hashmap(原节点->新节点)就可以解决，时间复杂度可以控制在O(2n)；还有一个很重要的点就是**不要忘记边界条件！！！即初始链表为空的情况**，否则无法通过所有测试用例

2. 哈希表与索引

| 序号 | 题目 | 备注
|-|-|-
| 1 | 两数之和 |  (简单题)unordered_map简单应用，时间复杂度O(n)
| 599 | 两个列表的最小索引总和 | (简单题)unordered_map简单应用 [但是leetcode是机翻的，You need to help them find out their common interest with the least list index sum. ，却翻译成了 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 with的意思翻译错了。 正确翻译应该是：你需要帮助他们找到索引和最小的共同喜爱的餐厅，即首先必须是双方共同感兴趣的餐厅，其次这家餐厅在两个数组中出现位置的索引和最小。]
| 219 | 存在重复元素 II | (简单题)unordered_map简单应用，时间复杂度O(n) （还可以用滑动窗口来解题）

3. 哈希表与统计

| 序号 | 题目 | 备注
|-|-|-
| 594 | 最长和谐子序列 | (简单题) 方法1：哈希表-unordered_map的遍历使用；方法2：可以将数组按照从小到大进行排序，我们只需要依次找到相邻两个连续相同元素的子序列，检查该这两个子序列的元素的之差是否为 1
| 350 | 两个数组的交集 II | (简单题)两个unordered_map的应用，一个小技巧：将判断放到第二个循环里，而不用再开第三个循环
| 554 | 砖墙 | 直接模拟法会超时，因此引入hashmap存储在某一列存在缝隙的个数
| 609 | 在系统中查找重复文件 | 主要涉及到字符串的拆分!!(要学会用封装好的函数find、substr等)，其次这题的存储结构要有印象
| 454 | 四数相加 II | 

4. 哈希表与前缀和

*这一子类要好好回顾下，第一次做的时候掌握的不是很好*

| 序号 | 题目 | 备注
|-|-|-
| 560 | 和为K的子数组 | 一时卡住了，前缀和两种方式：枚举或哈希优化（感觉滑动窗口也能做，但是边界很不好找）
| 523 | 连续的子数组和 | 和560的解题思路有异曲同工之妙，但是更为进阶。有三种解法，这道题值得分析！
| 525 | 连续数组 | 560、523、525是同一类题，要仔细看下，常规的枚举方法也能做，但往往会出现超时的情况。主要是掌握如何用hash进行优化——因为直接把前缀和作为key经常是行不通的

### 栈与队列篇

#### 知识点

#### 做题列表

1. 栈的实现

| 序号 | 题目 | 备注
|-|-|-
| 232 | 用栈实现队列 | 一个入栈，一个出栈
| 225 | 用队列实现栈 | 一个队列维护的是真实的栈顺序，另一个队列当作辅助队列进行插入（push）