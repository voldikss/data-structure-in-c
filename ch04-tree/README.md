# 二叉树

- 实现

- 三种遍历方法

- 构造表达式树的算法
  遇到数压栈，遇到操作符弹出并构造树并压栈

# 二叉查找树

- 查找
- 插入
- 删除：右子树的最小的数据代替该节点的数据并递归地删除那个节点

# 有平衡条件的二叉查找树：AVL 树

- 单旋转
- 双旋转

# 伸展树(读得比较粗略)

- 展开方法
  - 双旋转
  - 一字旋转

当一个节点被访问，他就必须被移动。

展开操作不仅将访问的节点移动到根处，而且还把访问路径上的大部分节点的深度大致减少一半。

当访问路径太长超出正常查找的时候，这些旋转对未来的操作有益。当访问耗时很少的时候，这些旋转则不那么有益。

# B树(读得比较粗略)
