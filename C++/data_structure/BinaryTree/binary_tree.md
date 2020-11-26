# Binary Tree


##[树的基本概念](https://mp.weixin.qq.com/s?__biz=MzUxODAzNDg4NQ==&mid=2247486511&idx=2&sn=2511ba9175ad6e4ae08759404581ae1f&chksm=f98e4885cef9c19378737194492745bc98908885fa4422f164ea89dddc6fa169c10f4d248294&mpshare=1&scene=1&srcid=1029qkGYTmkJorxF1I1atqpg&sharer_sharetime=1603934463631&sharer_shareid=87c63c66f42a4150bca9a3d2a69b5061&exportkey=A1fj%2FPtgnqWfA8wbPpthBsc%3D&pass_ticket=PNyOTPON6a%2B35PySys5BAy7gtqF9nVRv4F4bvq9SbhTea29Nq9EzgLYxDPyHthK2&wx_header=0#rd) 

## 二叉树类型
* **满二叉树**:每个节点都有0或者2个子节点.
```cpp               
              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40

             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50

               18
            /     \  
          40       30  
                   /  \
                 100   40
```
* **完全二叉树**: 一棵二叉树至多只有最下面的一层上的结点的度数可以小于2，并且最下层上的结点都集中在该层最左边的若干位置上.
```cpp
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 
```
* 完美二叉树:所有内部节点都有两个子节点，并且所有的叶子节点都在同一层.
```cpp
              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
```
* 二叉搜索树(binary search trees(BST)):二叉树上所有节点的，左子树上的节点都小于根节点，右子树上所有节点的值都大于根节点. 二叉查找树的查询复杂度取决于目标节点的深度，因此当节点的深度比较大时，最坏的查询效率是O(n).而AVL树和红黑树，可以将最坏效率降低至O(log n)。  
* 平衡二叉树(又被称为AVL树):在二叉查找树中，任一节点对应的两棵子树的最大高度差为 1，这样的二叉查找树称为平衡二叉树.  
* 红黑树:红黑树也是一种特殊的「二叉查找树」, 
> 1. 节点是红色或黑色。
> 2. 根是黑色。
> 3. 所有叶子都是黑色（叶子是NIL节点）。
> 4. 每个红色节点必须有两个黑色的子节点。（从每个叶子到根的所有路径上不能有两个连续的红色节点。）
> 5. 从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点。
> 这些约束确保了红黑树的关键特性：从根到叶子的最长的可能路径不多于最短的可能路径的两倍长。

## 二叉树遍历
* BFS(Breadth First Traversal(Level Order Traversal))
* DFS(Depth First Traversals
  > 1. Inorder(中序) Traversal (Left-Root-Right)  
  > 2. Preorder(前序) Traversal (Root-Left-Right)  
  > 3. Postorder(后序) Traversal (Left-Right-Root)  
  > 三种遍历区别在于根节点(root)访问位置，左子树始终先于右子树.  