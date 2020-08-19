# LQR(apollo)

## LQR(linear quadratic regulator):
**[LQR横向控制1](https://blog.csdn.net/zhouyy858/article/details/107606500#commentBox)**  
**[LQR横向控制2](https://mp.weixin.qq.com/s?__biz=MzU5ODMzNjgyOQ==&mid=2247484188&idx=1&sn=ff1ceeb167dba714c34bd783e29c5e3e&chksm=fe44f74ec9337e580dce97221c68420294af323bbad59521d254a661a6a9a2f25b8bd619fb85&mpshare=1&scene=24&srcid=0813688oA8i6nGBI1xrD64fg&sharer_sharetime=1597308597093&sharer_shareid=87c63c66f42a4150bca9a3d2a69b5061&exportkey=A%2FtDWpvREGfMGHBbn8yXZ1Q%3D&pass_ticket=iKiIC0PPXpaN2GsRRpg3wB0jFaUVyftIpZkZjdAjmdcyoxOoEQpqAIY9G7W3lSkx&wx_header=0#rd)**  
**[LQR横向控制3](https://zhuanlan.zhihu.com/p/110239637)**

**若一系统动态可以用一组线性微分方程表示，且其成本为二次泛函，这类问题成为二次(LQ)问题，此类问题的解即为线性二次调节器(LQR)。**

1. 车辆的横向控制期望根据路径跟踪偏差能够快速、稳定的趋于零，并且保持平衡，同时前轮转角控制输入又尽可能小，这就是一个典型的目标优化控制问题。
2. 优化问题的目标函数可以表示为跟踪过程累计的跟踪误差和累计的控制输入的权重和：   
   $J = \int(x^TQx + u^TRu)dt$        
   其中：$Q$为半正定的状态权重矩阵，$R$为正定的控制权重矩阵.
3. 其中$J$是一个关于状态变量$x$和控制输入$u$的二次型目标函数，对它的求解是典型的LQR最优控制问题，求解最小目标函数$J$.
4. $Q$矩阵元素变大意味着希望跟踪偏差能够快速趋进于零，$J = \int(x^TQx)dt$ 表示跟踪过程路径偏差的累积大小.
   $R$矩阵元素变大意味着希望控制输入能够尽可能小. $J = \int(u^TRu)dt$ 表示跟踪过程控制能量的损耗.
5. 求解过程：
    - 通过一系列推到得到代数黎卡提方程：$P = A^T_dPA_d - A^T_dPB_d(R + B_dPB_d)^{-1}B^T_dPA_d + Q$ , 其中$A_d$和$B_d$是离散后的$A$和$B$矩阵.
    - 迭代代数黎卡提方程求出$P$
    - 当两次$P$的差值足够小时(通过tolerance:The numerical tolerance for solving Discrete
         Algebraic Riccati equation (DARE) 和 max_num_iteration:The maximum iterations for solving ARE)作为限制来快速求得最优解，计算反馈矩阵$K = (R + B^TPB)^{-1}(B^TPA)$
    - 根据$K$求出最优控制量$u = -Kx$
    - 通过一个前馈控制输入量$u_{ff}$，解决曲线行驶时的稳态误差，前馈控制考虑了路径的曲率及车辆的转向不足特性。


## Trajectory Analyzer:
* 功能：
   1. 查询路点: 根据坐标查询参考路径上到当前位置距离最近的点; 根据时间戳查询参考路径上到当前位置时间最近的点;
   2. 坐标转换(to Frenet坐标系): Frenet坐标系下当前位置到参考点的$s$、$d$、$\dot{s}$、$\dot{d}$


## 数学基础：
### 二次型[链接](https://www.zhihu.com/question/38902714)
1. 二次型：n个变量的二次齐次(每项都是二次的)多项式。

### 矩阵正定性[链接](https://zhuanlan.zhihu.com/p/44860862)：
1. 正定矩阵：给定一个大小为 $n×n$ 的**实对称矩阵** $A$ ，若对于任意长度为 $n$ 的非零向量 $x$ ，有 **$x^TAx > 0$** 恒成立，则矩阵 $A$ 是一个正定矩阵。
2. 半正定矩阵：给定一个大小为 $n×n$ 的**实对称矩阵** $A$ ，若对于任意长度为 $n$ 的非零向量 $x$ ，有 **$x^TAx \geq 0$** 恒成立，则矩阵 $A$ 是一个正定矩阵。

### discrete-time Algebraic Riccati equation:
* 代数黎卡提方程与黎卡提方程的区别：
离散时间代数黎卡提方程(DARE)可以由矩阵值的黎卡提微分方程的非时变解来验证。