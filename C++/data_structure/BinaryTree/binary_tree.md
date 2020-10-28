# Binary Tree

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
  
* 平衡二叉树(又被称为AVL树):是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树.
* 二叉搜索树(binary search trees(BST))
* 红黑树

## 二叉树遍历
* BFS(Breadth First Traversal(Level Order Traversal))
* DFS(Depth First Traversals
  > 1. Inorder(中序) Traversal (Left-Root-Right)  
  > 2. Preorder(前序) Traversal (Root-Left-Right)  
  > 3. Postorder(后序) Traversal (Left-Right-Root)  
  > 三种遍历区别在于根节点(root)访问位置，左子树始终先于右子树.  