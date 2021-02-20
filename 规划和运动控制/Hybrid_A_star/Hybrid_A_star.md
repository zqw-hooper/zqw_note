# Hybrid_A*
## A*
[A*算法](https://scm_mos.gitlab.io/motion-planner/a-star/)：是一种静态路网中求解最短路最有效的方法,是把启发式方法（`heuristic approaches`），和常规方法如`Dijsktra`算法结合在一起的算法,启发式方法经常给出一个近似解而不是保证最佳解。然而，尽管`A star`基于无法保证最佳解，`A star`却能保证找到一条最短路径.  
1. `A*`算法节点定义：
  ```cpp
    struct AstarNode
    {
        NodeStatus status = NodeStatus::None;  // node status
        double x;                              // x
        double y;                              // y
        double theta;                          // theta
        double gc = 0;                         // actual cost：表示从初始结点到任意结点`n`的代价
        double hc = 0;                         // heuristic cost：表示从结点`n`到目标点的启发式评估代价
        bool is_back;                          // true if the current direction of the vehicle is back
        AstarNode * parent = nullptr;          // parent node
        double cost() const { return gc + hc; }
    };
  ```

2. 将`costmap`变换为`std::vector<std::vector<std::vector<AstarNode>>> nodes(height, width, theta_size)`, 其中`theta_size`为角度颗粒度.  
3. `createTransitionTable`

















* A*与Hybrid_A*区别在于Hybrid_A*考虑了车辆的约束条件(转向盘转角限制).  
* 