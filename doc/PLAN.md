# 数据结构与算法实现规划

参考书目：Sartaj Sahni《数据结构、算法与应用（C++ 语言描述）》第 2 版。

> 说明：本工程使用 C 语言（C11）手写实现书中的数据结构与算法。
> `main.c` 为遗留代码，不计入本规划；`main.c` 将在各模块迁移完成后删除或仅保留演示入口。

## 一、工程约定

- 实现文件：`bases/my_xxx.c`
- 头文件：`bases/include/my_xxx.h`
- 命名风格：`snake_case`，结构体/类型使用 `PascalCase`，函数统一前缀（如 `list_`、`stack_`、`queue_`）
- 头文件使用 `#ifndef` 卫哨
- 应用/演示程序：`apps/chXX/主题.c`
- 单元测试：`tests/`
- 构建：CMake，`add_library(ds ...)` + 每章一个 `add_executable`，启用 `enable_testing()`

## 二、已有代码（需要整理）

- [ ] `bases/my_stack.c/.h` 链式栈：修正拼写（`stcak_init`、`Stack_push`），`stack_free` 补充 `return`
- [ ] `bases/my_queue.c/.h`：修正文件名/字段拼写（`my_quene`→`my_queue`，`date`→`data`）
- [ ] `bases/my_list.c/.h` 单向链表：`my_list.c` 仅有函数声明，需补全实现
- [ ] `bases/my_list.c/.h` 增加统一的错误处理与内存释放约定

## 三、按章节实现清单

### 第 2 章 性能分析（基础排序与查找）

- [ ] `my_sort.c` / `my_sort.h`：顺序查找、二分查找、选择排序、冒泡排序、插入排序、名次排序、多项式求值

### 第 5 章 线性表——数组描述

- [ ] `my_arraylist.c` / `my_arraylist.h`：动态顺序表（insert/erase/get/indexOf/size/resize/output）

### 第 6 章 线性表——链式描述

- [ ] `my_linkedlist.c` / `my_linkedlist.h`：单向链表（在 `my_list` 基础上整理）
- [ ] `my_dlist.c` / `my_dlist.h`：双向链表
- [ ] `my_circularlist.c` / `my_circularlist.h`：带头结点循环链表
- [ ] `my_unionfind.c` / `my_unionfind.h`：并查集（数组版 + 链式版）

### 第 7 章 数组与矩阵

- [ ] `my_matrix.c` / `my_matrix.h`：通用二维矩阵（加/乘/转置）
- [ ] `my_diagonalmatrix.c` / `my_diagonalmatrix.h`：对角矩阵
- [ ] `my_tridiagonalmatrix.c` / `my_tridiagonalmatrix.h`：三对角矩阵
- [ ] `my_lowertriangular.c` / `my_lowertriangular.h`：下三角矩阵
- [ ] `my_sparsematrix.c` / `my_sparsematrix.h`：稀疏矩阵（三元组表）
- [ ] `my_linkedmatrix.c` / `my_linkedmatrix.h`：链表矩阵

### 第 8 章 栈

- [ ] `my_stack.c` / `my_stack.h`：数组栈 + 链式栈（统一接口）
- [ ] `apps/ch08/parenthesis.c`：括号匹配
- [ ] `apps/ch08/hanoi.c`：汉诺塔（递归 + 显式栈）
- [ ] `apps/ch08/railroad.c`：车厢重排
- [ ] `apps/ch08/switchbox.c`：开关盒布线
- [ ] `apps/ch08/equivalence.c`：等价类划分
- [ ] `apps/ch08/maze.c`：迷宫求解

### 第 9 章 队列

- [ ] `my_queue.c` / `my_queue.h`：循环数组队列 + 链式队列
- [ ] `apps/ch09/wire_router.c`：布线问题（迷宫最短路）
- [ ] `apps/ch09/component_labeling.c`：连通分支标记
- [ ] `apps/ch09/machine_shop.c`：车间仿真（事件队列）

### 第 10 章 跳表与散列

- [ ] `my_skiplist.c` / `my_skiplist.h`：跳表
- [ ] `my_sortedchain.c` / `my_sortedchain.h`：有序链表字典
- [ ] `my_hashtable.c` / `my_hashtable.h`：开放寻址散列表
- [ ] `my_hashchains.c` / `my_hashchains.h`：链地址法散列
- [ ] `apps/ch10/compress.c`、`apps/ch10/decompress.c`：LZW 压缩/解压

### 第 11 章 二叉树与其他树

- [ ] `my_binarytree.c` / `my_binarytree.h`：二叉树结点、前/中/后/层序遍历（递归 + 栈/队列）
- [ ] `my_linkedbinarytree.c` / `my_linkedbinarytree.h`：链式二叉树的按序建树
- [ ] `my_unionfind_tree.c` / `my_unionfind_tree.h`：树结构并查集（加权规则 + 路径压缩）
- [ ] `apps/ch11/infix.c`：中缀表达式转后缀/表达式树
- [ ] `apps/ch11/booster.c`：信号增强器

### 第 12 章 优先级队列

- [ ] `my_maxheap.c` / `my_maxheap.h`：最大堆（优先级队列）
- [ ] `my_hblt.c` / `my_hblt.h`：高度优先左高树
- [ ] `my_heapsort.c` / `my_heapsort.h`：堆排序
- [ ] `apps/ch12/lpt_schedule.c`：LPT 调度
- [ ] `apps/ch12/huffman.c`：哈夫曼编码

### 第 13 章 竞赛树

- [ ] `my_winningtree.c` / `my_winningtree.h`：赢者树
- [ ] `my_losingtree.c` / `my_losingtree.h`：输者树
- [ ] `apps/ch13/first_fit.c`：首次适应装箱

### 第 14 章 二叉搜索树

- [ ] `my_bst.c` / `my_bst.h`：BST（insert/delete/find/遍历）
- [ ] `my_indexedbst.c` / `my_indexedbst.h`：带索引的 BST（按名次查找）
- [ ] `my_dict.c` / `my_dict.h`：字典抽象
- [ ] `apps/ch14/histogram.c`：直方图统计
- [ ] `apps/ch14/best_fit.c`：最佳适应装箱
- [ ] `apps/ch14/crossings.c`：交叉统计分析

### 第 15 章 平衡搜索树

- [ ] `my_avl.c` / `my_avl.h`：AVL 树
- [ ] `my_redblacktree.c` / `my_redblacktree.h`：红黑树
- [ ] `my_23tree.c` / `my_23tree.h`：2-3 树
- [ ] `my_btree.c` / `my_btree.h`：B 树

### 第 16 章 图

- [ ] `my_graph.c` / `my_graph.h`：邻接矩阵图（有向/无向）
- [ ] `my_linkedgraph.c` / `my_linkedgraph.h`：邻接链表图
- [ ] `my_graph_algo.c` / `my_graph_algo.h`：BFS/DFS、拓扑排序、连通分量、生成树、Dijkstra、Bellman-Ford、Floyd

### 第 17 章 贪婪算法

- [ ] `my_greedy.c` / `my_greedy.h`：装箱、分数背包、哈夫曼、Kruskal、Prim、Dijkstra、拓扑排序

### 第 18 章 分而治之

- [ ] `my_divide.c` / `my_divide.h`：归并排序、快速排序、第 k 小元素、最近点对、棋盘覆盖

### 第 19 章 动态规划

- [ ] `my_dp.c` / `my_dp.h`：0/1 背包、矩阵连乘、最长公共子序列、全源最短路、非交叉子集

### 第 20 章 回溯法

- [ ] `my_backtrack.c` / `my_backtrack.h`：装载问题、0/1 背包、n 皇后、子集和、图着色、哈密顿回路

### 第 21 章 分支限界

- [ ] `my_branchbound.c` / `my_branchbound.h`：FIFO 装载、最大收益装载、0/1 背包、最短路径、旅行商问题

## 四、实施顺序建议

1. 基础层：整理栈/队列/链表，补全 `my_arraylist`、`my_linkedlist`，搭建 CMake 库与测试框架
2. 线性结构：第 5–7 章（数组表、链式表、矩阵）
3. 树与查找：第 11 → 12 → 14 → 15 章，第 10 章散列
4. 图与基础算法：第 16 章，第 2 章排序
5. 算法设计方法：第 17 → 18 → 19 → 20 → 21 章
6. 每完成一章，在 `apps/chXX/` 添加驱动程序，并在 `main.c` 中汇总演示入口

## 五、完成标准

- 每个数据结构具备初始化、增删改查、销毁（无内存泄漏）
- 每个算法对边界条件（空、满、单元素）均有处理
- 每章至少一个可运行的应用/演示程序
- `tests/` 中对应模块通过基础单元测试
