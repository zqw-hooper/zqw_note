# MPC(Model Predictive Control)

## 预测模型
**车辆动力学模型推导：**  
<img src="../../image/vehicle_dymnamic1.jpeg" width="75%" height="75%" />  
<img src="../../image/vehicle_dymnamic2.jpeg" width="75%" height="75%" />  
<img src="../../image/vehicle_dymnamic3.jpeg" width="75%" height="75%" /> 

**Path Coordinates模型:**[模型推倒](https://blog.csdn.net/u013914471/article/details/83018664)  
<img src="../../image/screenshot_steer_wheel_model.png" width="65%" height="50%" />

**状态方程离散化:**   
<img src="../../image/linear_state_function_discrete.jpeg" width="65%" height="50%" />  

**基于车辆模模型的预测** [基于车辆模型的预测及二次规划代价函数](https://zhuanlan.zhihu.com/p/72738458)  
* 基于Path Coordinates模型可以得到未来$n$时刻状态：  
<img src="../../image/prediction_formula.svg" width="65%" height="50%" />  

* 假设未来$n$时刻车速恒定：  
<img src="../../image/prediction_base_on_vehicle_model.jpeg" width="65%" height="50%" />  

