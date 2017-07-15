# RungeKutta45
Runge Kutta numerical integration method in C++, 较为通用性的龙格库塔四阶五步积分（固定步长）

# 使用

编写一阶微分方程头文件以及主函数即可（本程序不能做到变步长，旨在规范化函数接口，即只需编写一阶微分方程与主函数，积分部分不用做任何改动）

# 示例

求解以下微分方程：

dy = 10 * x * (1 - y)

y(0) = 0

步长h = 0.05, 并与解析解y = 1 - exp(-5 * x * x)比较。

编写一阶微分方程如`DynamicModel.h`，编写主函数如`main_test.cpp`。
